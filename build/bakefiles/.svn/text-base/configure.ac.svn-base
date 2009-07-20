        AC_PREREQ(2.57)
        AC_INIT([myprog], [1.2.3], [mymail@myserver.com])
        
        # This allows us to use Bakefile, recognizing the system type
        # (and sets the AC_CANONICAL_BUILD, AC_CANONICAL_HOST and
        # AC_CANONICAL_TARGET variables)
        AC_CANONICAL_SYSTEM
        
        # This adds some standard wxWidgets options to the configure script
        AM_OPTIONS_WXCONFIG
        
        # Check for wxWidgets
        # ===================
        
     AM_PATH_WXCONFIG(2.6.0, wxWin=1, wxWin=0)
     if test "$wxWin" != 1; then
        AC_MSG_ERROR([
           wxWidgets must be installed on your system
           but wx-config script couldn't be found.
        
           Please check that wx-config is in path, the directory
           where wxWidgets libraries are installed (returned by
           'wx-config --libs' command) is in LD_LIBRARY_PATH or
           equivalent variable and wxWidgets version is 2.6.0 or above.
        ])
     else
        # do not update CPPFLAGS nor CXXFLAGS otherwise we'll get the
        # same settings repetead three times (since Makefile.in merges these
        # two variables with $WX_CPPFLAGS automatically)
        #CPPFLAGS="$CPPFLAGS"
        CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS"
        CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
        LDFLAGS="$LDFLAGS $WX_LIBS"
     fi
        
     # Synch our WX_DEBUG,WX_UNICODE,WX_SHARED variables with wx ones
     # ==============================================================
     
     # these var will be set to '0' when they are FALSE, '1' when they are TRUE
        #
        # IMPORTANT: remove the space between the two hyphens when creating your
        #            configure.ac files from the following lines !
        #
     UNICODE_FLAG=$(test ! $($WX_CONFIG_WITH_ARGS --unicode >/dev/null 2>&1))
     DEBUG_FLAG=$(test ! $($WX_CONFIG_WITH_ARGS --debug >/dev/null 2>&1))
     SHARED_FLAG=$($WX_CONFIG_WITH_ARGS --static >/dev/null 2>&1)
     
     AC_MSG_CHECKING([if wxWidgets was built with UNICODE enabled])
     if test "$UNICODE_FLAG" != "0"; then
        AC_MSG_RESULT([yes])
        WX_UNICODE=1
     else
        AC_MSG_RESULT([no])
        WX_UNICODE=0
     fi
     
     
     AC_MSG_CHECKING([if wxWidgets was built in DEBUG or RELEASE mode])
     if test "$DEBUG_FLAG" != "0"; then
        AC_MSG_RESULT([debug])
        WX_DEBUG=1
     else
        AC_MSG_RESULT([release])
        WX_DEBUG=0
     fi
     
     AC_MSG_CHECKING([if wxWidgets was built in SHARED or STATIC mode])
     if test "$SHARED_FLAG" != "0"; then
        AC_MSG_RESULT([shared])
        WX_SHARED=1
     else
        AC_MSG_RESULT([static])
        WX_SHARED=0
     fi
        
        # The final lines of the configure script
        AC_BAKEFILE([m4_include(autoconf_inc.m4)]) 
        AC_CONFIG_FILES([Makefile])
        AC_OUTPUT 
