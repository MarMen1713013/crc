project(
  'gencrc',
  'c',
  version: '0.1.0',
  default_options: [
    'c_std=c11',
    'buildtype=release',
    ]
  )

gencrc_lib = library(
  'gencrc',
  sources: files('include/crc.c'),
  include_directories: include_directories('include'),
  install: false,
  )

dgencrc_lib = shared_library(
  'dgencrc',
  sources: files('include/crc.c'),
  include_directories: include_directories('include'),
  install: true,   # installa la .so
)

gencrc_dep = declare_dependency(
  link_with: gencrc_lib,
  include_directories: include_directories('include'),
  )

dgencrc_dep = declare_dependency(
  link_with: dgencrc_lib,
  include_directories: include_directories('include'),
  )

subdir('src')
