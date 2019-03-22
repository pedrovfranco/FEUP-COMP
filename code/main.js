let lines = [];
let flags = [];
let catFlags = [];

function parseFlags()
{
	for (let i = 1; i < lines.length; i++)
	{
		let line = lines[i];

		if (line.search("-") == -1 && flags.length != 0)
		{
			flags[flags.length-1][1] 
= 
flags[flags.length-1][1].concat(line.replace(/\s\s+/g, 
" ").replace(/\r/g, "").replace(".", ""));
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


function categorizeFlags()
{
	catFlags["generic"] = [];
	catFlags["recursive"] = [];
	catFlags["loop"] = [];
	catFlags["c string"] = [];

	for (let i = 0; i < flags.length; i++)
	{
		if (flags[i][1].search("loop") != -1)
		{
			catFlags["loop"].push(flags[i]);
		}
		else if (flags[i][1].search("recurs") != -1)
		{
			catFlags["recursive"].push(flags[i]);
		}
		else if (flags[i][1].search("c string") != -1)
		{
			catFlags["c string"].push(flags[i]);
		}
		else
		{
			catFlags["generic"].push(flags[i]);
		}
	}
}


function printCatFlags()
{
	for (let catIndex in catFlags)
	{
		console.log(catIndex + ":\n");
		let category = catFlags[catIndex];
		for (let i = 0; i < category.length; i++)
		{
			console.log(category[i]);
		}
		console.log("\n\n");
	}
}

const { exec } = require('child_process');
exec('cat flags.txt', (err, stdout, stderr) =>
{
	if (err)
	{
		console.log("Node couldn't execute the command!");
		return;
	}
	else
	{
		lines = stdout.split("\n");
		parseFlags();

/*		for (let i = 0; i < flags.length && i < 5; i++)
		{
			console.log(flags[i]);
		}
*/
		categorizeFlags();

		printCatFlags();
	}

});


