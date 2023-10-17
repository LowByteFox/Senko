project('Senko', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

curl = dependency('libcurl')

executable('senko', ['senko.c', 'src/img.c'], dependencies : curl)
