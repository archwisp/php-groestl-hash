--TEST--
Test function groestl_hash() by calling it with unexpected arguments
--CREDITS--
Bryan C. Geraghty <bryan@ravensight.org>
--SKIPIF--
<?php if (!extension_loaded("groestl")) print "skip"; ?>
--FILE--
<?php

$data = "\xde\xad\xbe\xef";

var_dump(groestl_hash());
var_dump(groestl_hash($data, 512, 'Extra argument'));
var_dump(groestl_hash($data, 'Foobar'));
var_dump(groestl_hash($data, 1024));

?>
--EXPECTF--
Warning: groestl_hash() expects at least 1 parameter, 0 given in %s on line %d
bool(false)

Warning: groestl_hash() expects at most 2 parameters, 3 given in %s on line %d
bool(false)

Warning: groestl_hash() expects parameter 2 to be long, string given in %s on line %d
bool(false)

Warning: groestl_hash(): Bad bit-length in %s on line %d
bool(false)

