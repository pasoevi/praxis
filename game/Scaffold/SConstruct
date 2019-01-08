import sys

platform = sys.platform
# Wextra
w = ' -Wall -Wstrict-prototypes -Wshadow -Wwrite-strings -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wstrict-aliasing'
cc = "gcc"

libs = Split('SDL2 SDL2_image SDL2_ttf m')

ccflags = '-g' # -pedantic' + w  
if platform == 'win32':
   ccflags += " -mwindows"
   libs.insert(0, 'SDL2main')
   libs.insert(0, 'mingw32')

build_dir = 'build' 
VariantDir(build_dir, 'src', duplicate=0)
env = Environment(CC = cc, CCFLAGS = ccflags, tools=['default', 'mingw'], TARFLAGS = '-c -z')





libpath = ['/usr/lib',
           '/usr/local/lib',
           'C:\SDL2\SDL2\i686-w64-mingw32\lib',
	   'C:\SDL2\SDL2-2.0.3\i686-w64-mingw32\lib',
           'C:\SDL2\SDL2_image-2.0.0\i686-w64-mingw32\lib',
           'C:\SDL2\SDL2_ttf-2.0.12\i686-w64-mingw32\lib']
cpppath = ['/usr/include/SDL2',
           'C:\SDL2\SDL2\i686-w64-mingw32\include',
	   'C:\SDL2\SDL2-2.0.3\i686-w64-mingw32\include',
           'C:\SDL2\SDL2_image-2.0.0\i686-w64-mingw32\include',
           'C:\SDL2\SDL2_ttf-2.0.12\i686-w64-mingw32\include',
           'C:\SDL2\SDL2\i686-w64-mingw32\include\SDL2',
	   'C:\SDL2\SDL2-2.0.3\i686-w64-mingw32\include\SDL2',
	   ]

src_files = Glob('build/*.c')
Command("build/graphics", "assets/graphics", Copy("build/${SOURCE.file}", "$SOURCE"))
Command("build/fonts", "assets/fonts", Copy("build/${SOURCE.file}", "$SOURCE"))
Command("build/levels", "assets/levels", Copy("build/${SOURCE.file}", "$SOURCE"))
for lib in Glob('lib/*.dll'):
   Command("build/${SOURCE.file}", lib, Copy("build/${SOURCE.file}", "$SOURCE"))

env.Program(source = src_files, target = 'build/scaffold', LIBS=libs,
LIBPATH=libpath, CPPPATH=cpppath)
if(platform == 'win32'):
   env.Zip('release/scaffold-win32.zip', ['build'])
else:
   env.Tar('release/scaffold-gnu-linux.tar.gz', ['build'])

Clean('.', build_dir)
