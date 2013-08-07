/*
 * GET home page.
 */

var rpiGpio = require('../gpio.js');

/**
*
* Home page definition
*
**/

exports.index = function(req, res) {
	res.render('index', {
		title: 'Express'
	});
};

/**
*
* GPIO controller
*
**/
exports.gpioOn = function(req, res) {
	rpiGpio.on(16);
	res.send('gpio 16 on');
};

exports.gpioOff = function(req, res) {
	rpiGpio.off(16);
	res.send('gpio 16 off');
};

exports.gpio = function(req, res) {
	if (req.query.pin === '16' && (req.query.act === '0' || req.query.act === '1')) {
		rpiGpio.act(req.query.pin, req.query.act);
		res.send('Action successfully');
	} else {
		//res.send(404, 'Action failed: ' + 'act: ' + req.query.act + ' pin: ' + req.query.pin);
		var body = 'Hello World';
		res.setHeader('Content-Type', 'text/plain');
		res.setHeader('Content-Length', body.length);
		res.end(body);
	}
};