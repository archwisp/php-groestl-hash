--TEST--
Test function groestl_hash() by calling it with expected arguments
--CREDITS--
Bryan C. Geraghty <bryan@ravensight.org>
--SKIPIF--
<?php if (!extension_loaded("groestl")) print "skip"; ?>
--FILE--
<?php

$data = "\xde\xad\xbe\xef";

var_dump(base64_encode(groestl_hash($data)));
var_dump(base64_encode(groestl_hash($data, 512)));
var_dump(base64_encode(groestl_hash($data, 256)));
var_dump(base64_encode(groestl_hash($data, 128)));
var_dump(base64_encode(groestl_hash($data, 64)));
var_dump(base64_encode(groestl_hash($data, 32)));

?>
--EXPECT--
string(88) "tXrfAhk8po+eH3tmUgESa4Sdr4RPe8HmkSXEytFz9I0i1/FFGlXzuz/lW7ZQJ4ODjg8wmc8sm2y3XDTc81SKDg=="
string(88) "tXrfAhk8po+eH3tmUgESa4Sdr4RPe8HmkSXEytFz9I0i1/FFGlXzuz/lW7ZQJ4ODjg8wmc8sm2y3XDTc81SKDg=="
string(44) "Q0045cAHRvoYsur3LG9TbcfUe3fzKHgSGTefjytlSYE="
string(24) "zVibVIxWUezKon/gynOirQ=="
string(12) "POGoPBO2h4Y="
string(8) "98XZsQ=="

