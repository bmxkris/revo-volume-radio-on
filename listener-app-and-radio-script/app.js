const http = require('http');
var morgan = require('morgan')
var logger = morgan('combined')
var url = require('url');

const PORT = 9998;

const volume = {
  2: "10",
  13: "12"
}

const server = http.createServer((req, res) => {
  logger(req, res, function (err) {

    var params = url.parse(req.url, true).query;
    const button = params['button'];
    // console.log(volume[button])
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.end('OK');
    const exec = require('child_process').exec;
    var yourscript = exec(`python3.9 revo.py ${volume[button]}`,
      (error, stdout, stderr) => {
        if (error !== null) {
          console.log('exec error: ${error}');
          process.abort()
        }
      }
    )
    yourscript.stdout.pipe(process.stdout)
    yourscript.on('exit', function() {
      console.log('Child script has finished')
    })
  })
});

server.listen(PORT, () => {
  console.log(`Server running on port ${PORT}.`);
});

