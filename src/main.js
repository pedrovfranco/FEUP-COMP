const path = require('path');
let flags = [];
let catFlags = [];


let O1 = [
	"-fauto-inc-dec",
	"-fbranch-count-reg",
	"-fcombine-stack-adjustments",
	"-fcompare-elim",
	"-fcprop-registers",
	"-fdce",
	"-fdefer-pop",
	"-fdelayed-branch",
	"-fdse",
	"-fforward-propagate",
	"-fguess-branch-probability",
	"-fif-conversion",
	"-fif-conversion2",
	"-finline-functions-called-once",
	"-fipa-profile",
	"-fipa-pure-const",
	"-fipa-reference",
	"-fipa-reference-addressable",
	"-fmerge-constants",
	"-fmove-loop-invariants",
	"-fomit-frame-pointer",
	"-freorder-blocks",
	"-fshrink-wrap",
	"-fshrink-wrap-separate",
	"-fsplit-wide-types",
	"-fssa-backprop",
	"-fssa-phiopt",
	"-ftree-bit-ccp",
	"-ftree-ccp",
	"-ftree-ch",
	"-ftree-coalesce-vars",
	"-ftree-copy-prop",
	"-ftree-dce",
	"-ftree-dominator-opts",
	"-ftree-dse",
	"-ftree-forwprop",
	"-ftree-fre",
	"-ftree-phiprop",
	"-ftree-pta",
	"-ftree-scev-cprop",
	"-ftree-sink",
	"-ftree-slsr",
	"-ftree-sra",
	"-ftree-ter",
	"-funit-at-a-time"
];

let O2 = [
	"-falign-functions",
	"-falign-jumps",
	"-falign-labels",
	"-falign-loops",
	"-fcaller-saves",
	"-fcode-hoisting",
	"-fcrossjumping",
	"-fcse-follow-jumps",
	"-fcse-skip-blocks",
	"-fdelete-null-pointer-checks",
	"-fdevirtualize",
	"-fdevirtualize-speculatively",
	"-fexpensive-optimizations",
	"-fgcse",
	"-fgcse-lm",
	"-fhoist-adjacent-loads",
	"-finline-small-functions",
	"-findirect-inlining",
	"-fipa-bit-cp",
	"-fipa-cp",
	"-fipa-icf",
	"-fipa-ra",
	"-fipa-sra",
	"-fipa-vrp",
	"-fisolate-erroneous-paths-dereference",
	"-flra-remat",
	"-foptimize-sibling-calls",
	"-foptimize-strlen",
	"-fpartial-inlining",
	"-fpeephole2",
	"-freorder-blocks-and-partition",
	"-freorder-functions",
	"-frerun-cse-after-loop",
	"-fschedule-insns",
	"-fschedule-insns2",
	"-fsched-interblock",
	"-fsched-spec",
	"-fstore-merging",
	"-fstrict-aliasing",
	"-fthread-jumps",
	"-ftree-builtin-call-dce",
	"-ftree-pre",
	"-ftree-switch-conversion",
	"-ftree-tail-merge",
	"-ftree-vrp"
];

let O3 = [
	"-fgcse-after-reload",
	"-finline-functions",
	"-fipa-cp-clone",
	"-floop-interchange",
	"-floop-unroll-and-jam",
	"-fpeel-loops",
	"-fpredictive-commoning",
	"-fsplit-paths",
	"-ftree-loop-distribute-patterns",
	"-ftree-loop-distribution",
	"-ftree-loop-vectorize",
	"-ftree-partial-pre",
	"-ftree-slp-vectorize",
	"-funswitch-loops",
	"-fvect-cost-model",
	"-fversion-loops-for-strides"
];

function parseFlags(lines)
{
	for (let i = 1; i < lines.length; i++)
	{
		let line = lines[i];

		if (line.search("-") == -1 && flags.length != 0)
		{
			flags[flags.length-1][1] = flags[flags.length-1][1].concat(line.replace(/\s\s+/g, " ").replace(/\r/g, "").replace(".", ""));
			continue;
		}

		let pos = line.search("-f");

		if (pos == -1)
			continue;

		let j, flag = false;
		for (j = pos; j < line.length; j++)
		{
			let currChar = line.charAt(j);

			if (currChar == ' ')
			{
				flag = true;
				continue;
			}

			else if (flag)
				break;
		}

		let flagName = line.substr(pos, j-2).trim();

		if (flagName.search("=") != -1)
			continue;

		let description = line.substr(j).replace("\r", "").replace(".", "");

		flags.push([flagName, description]);
	}
}


function searchKeyword(flag, keyword)
{
	return (flag[0].search(keyword) != -1 || flag[1].search(keyword) != -1);
}


function categorizeFlags()
{
	catFlags["generic"] = [];
	catFlags["recursive"] = [];
	catFlags["loop"] = [];
	catFlags["float"] = [];
	catFlags["string"] = [];
	catFlags["math"] = [];
	catFlags["IRA"] = [];
	catFlags["scheduler"] = [];
	catFlags["CSE"] = [];


	for (let i = 0; i < flags.length; i++)
	{
		if (searchKeyword(flags[i], "loop"))
		{
			catFlags["loop"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "math"))
		{
			catFlags["math"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "recurs"))
		{
			catFlags["recursive"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "string"))
		{
			catFlags["string"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "float"))
		{
			catFlags["float"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "IRA"))
		{
			catFlags["IRA"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "scheduler"))
		{
			catFlags["scheduler"].push(flags[i]);
		}
		else if (searchKeyword(flags[i], "CSE") || searchKeyword(flags[i], "common subexpression elimination") )
		{
			catFlags["CSE"].push(flags[i]);
		}
		else if (O1.includes(flags[i][0]) || O2.includes(flags[i][0]) || O3.includes(flags[i][0]))
		{
			catFlags["generic"].push(flags[i]);
		}
		else
		{
			flags.splice(i, 1);
		}
	}
}


function printCatFlags()
{
	for (let catIndex in catFlags)
	{
		let category = catFlags[catIndex];
		console.log(catIndex + "(" + category.length + ")" + ":\n");

		for (let i = 0; i < category.length; i++)
		{
			console.log(category[i][0] + " : " + category[i][1]);
		}
		console.log("\n\n");
	}
}

function flagAvailable(flag)
{
	for (let i = 0; i < flags.length; i++)
	{
		if (flags[i][0] === flag)
			return true;
	}

	return false;
}

function compileWithFlags(src)
{
	let executableName = src.substr(0, src.lastIndexOf("."));

	let cmd = "g++ " + src + " -std=c++11 -o " + executableName;

	for (let i = 0; i < flags.length; i++)
	{
		cmd += " " + flags[i][0];
	}

	console.log(cmd);

	const { exec } = require('child_process');
	exec(cmd, (err, stdout, stderr) => {
		if (!err)
		{
			console.log("Compilation successful!");
		}
		else 
		{
			console.log(stderr);
			return;
		}
	});
}


// gcc --help=optimizers
const { exec } = require('child_process');
exec('g++ --help=optimizers', (err, stdout, stderr) =>
{	
	if (!err)
	{
		parseFlags(stdout.split("\n"));

		categorizeFlags();

		printCatFlags();

		compileWithFlags("src" + path.sep + "target" + path.sep + "main.cpp");
	}
	else
	{
		console.log(stderr);
		return;
	}
});


