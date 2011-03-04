PHP_ARG_ENABLE(groestl, whether to enable groestl support,
[  --enable-groestl          Enable groestl support])

if test "$PHP_GROESTL" != "no"; then
  PHP_NEW_EXTENSION(groestl, php_groestl.c Groestl-opt.c, $ext_shared)
fi
