


function fixSpaces()
{

}

console.log("ola mundo");


const { exec } = require('child_process');
exec('g++ --help=optimizers', (err, stdout, stderr) =>
{
	if (err)
	{
		console.log("Node couldn't execute the command!");
		return;
	}
	else // the *entire* stdout and stderr (buffered)
	{
		console.log("stdout: " + stdout);
		console.log("stderr: " + stderr);
	}
	
});