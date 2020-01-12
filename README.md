# AdvanceGCC

This is the collection of confusing but common tips in C-lang, `gcc`, `make` and `ld`.

# Preparations && Build

```sh
# version: 9.2.0
docker run -it -v $(pwd):/home/me -w /home/me --rm gcc
# inside docker
make
# When you run all sample programs..
make run
```

If you want to erase this, `make clean`.

# General

## gcc

### include

+ include files is `/usr/include` and `/usr/include/x86_64-linux-gnu/`.
The former has common files(linux, net, asm-generic..):

```sh
# ls -d /usr/include/*/
/usr/include/GL/	      /usr/include/libmount/	 /usr/include/netrose/
/usr/include/ImageMagick-6/   /usr/include/libpng/	 /usr/include/nettle/
/usr/include/OpenEXR/	      /usr/include/libpng16/	 /usr/include/nfs/
/usr/include/X11/	      /usr/include/librsvg-2.0/  /usr/include/openjpeg-2.1/
/usr/include/arpa/	      /usr/include/libwmf/	 /usr/include/openjpeg-2.3/
/usr/include/asm-generic/     /usr/include/libxml2/	 /usr/include/openssl/
/usr/include/blkid/	      /usr/include/libxslt/	 /usr/include/p11-kit-1/
/usr/include/c++/	      /usr/include/linux/	 /usr/include/pixman-1/
/usr/include/cairo/	      /usr/include/lqr-1/	 /usr/include/postgresql/
/usr/include/et/	      /usr/include/lzma/	 /usr/include/protocols/
/usr/include/event2/	      /usr/include/mariadb/	 /usr/include/rdma/
/usr/include/fontconfig/      /usr/include/misc/	 /usr/include/readline/
/usr/include/freetype2/       /usr/include/mit-krb5/	 /usr/include/rpc/
/usr/include/gdk-pixbuf-2.0/  /usr/include/mtd/		 /usr/include/rpcsvc/
/usr/include/gio-unix-2.0/    /usr/include/mysql/	 /usr/include/scsi/
/usr/include/glib-2.0/	      /usr/include/ncursesw/	 /usr/include/selinux/
/usr/include/gnutls/	      /usr/include/net/		 /usr/include/sepol/
/usr/include/gssapi/	      /usr/include/netash/	 /usr/include/sound/
/usr/include/gssrpc/	      /usr/include/netatalk/	 /usr/include/unicode/
/usr/include/iproute2/	      /usr/include/netax25/	 /usr/include/uuid/
/usr/include/kadm5/	      /usr/include/neteconet/	 /usr/include/video/
/usr/include/krb5/	      /usr/include/netinet/	 /usr/include/webp/
/usr/include/libdjvu/	      /usr/include/netipx/	 /usr/include/x86_64-linux-gnu/
/usr/include/libexif/	      /usr/include/netiucv/	 /usr/include/xcb/
/usr/include/libexslt/	      /usr/include/netpacket/	 /usr/include/xen/
/usr/include/libltdl/	      /usr/include/netrom/
```

The latter is as follows:

```sh
# ls /usr/include/x86_64-linux-gnu/
ImageMagick-6  c++	       ffitarget.h    ieee754.h    maxminddb_config.h  tiffconf.h
a.out.h        curl	       fpu_control.h  jconfig.h    openssl	       tiffio.h
asm	       expat_config.h  gmp.h	      libxslt	   sys		       tiffio.hxx
bits	       ffi.h	       gnu	      maxminddb.h  tiff.h	       tiffvers.h
```

`#include <sys/**.h>` or `#include <asm/**.h>` comes from the directorty.

## Makefile

### Reference

+ https://qiita.com/knknkn1162/items/c67ae7c2ef71a713adf8 : How to use `readelf`, `hexdump` and `ld`
+ https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html : implicit rule(official)
+ https://goth-wrist-cut.hatenadiary.org/entry/20080317/1205769293 : examples of `patsubst`, `foreach` and `shell`

### Implicit rules

For more details, see [the link](https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html):

+ `$(CC) -c $(CPPFLAGS) $(CFLAGS)` in C -> object file

+ `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)` in C++ -> object file

+ `$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) -o $@` in C -> exec file

+ `$(AS) $(ASFLAGS)` in asm

+ `$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@` in linker. The `ar` directory uses implicit rule on link

### PHONY

```make
# Makefile
compile_switch:
	make -C compile_switch
```

```sh
make compile_switch
make: 'compile_switch' is up to date.
```

This is because `compile_switch` directory has been already created before `make compile_swtich`.

To avoid this, write `.PHONY compile_switch` and you can fully compile this.

## Misc

+ If docker container was freezed, type Ctrl-C.

# Each Topic

For detailed information on each directory, check dir/README.md.
