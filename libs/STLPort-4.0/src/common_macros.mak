#
#  Directories
#
#

SRCDIR=.
STLPORT_DIR=..$(PATH_SEP)stlport
OUTDIR=..$(PATH_SEP)lib

RELEASE_OBJDIR_static=obj$(PATH_SEP)$(COMP)$(PATH_SEP)Release
DEBUG_OBJDIR_static=obj$(PATH_SEP)$(COMP)$(PATH_SEP)Debug
STLDEBUG_OBJDIR_static=obj$(PATH_SEP)$(COMP)$(PATH_SEP)DebugSTL
RELEASE_OBJDIR_dynamic=obj$(PATH_SEP)$(COMP)$(PATH_SEP)ReleaseD
DEBUG_OBJDIR_dynamic=obj$(PATH_SEP)$(COMP)$(PATH_SEP)DebugD
STLDEBUG_OBJDIR_dynamic=obj$(PATH_SEP)$(COMP)$(PATH_SEP)DebugSTLD


#
#
# Targets
#

RELEASE_NAME=$(LIB_BASENAME)
DEBUG_NAME=$(LIB_BASENAME)_debug
STLDEBUG_NAME=$(LIB_BASENAME)_stldebug

RELEASE_DYNLIB=$(RELEASE_NAME).$(DYNEXT)
DEBUG_DYNLIB=$(DEBUG_NAME).$(DYNEXT)
STLDEBUG_DYNLIB=$(STLDEBUG_NAME).$(DYNEXT)

RELEASE_LIB=$(RELEASE_NAME)$(STATIC_SUFFIX).$(STEXT)
DEBUG_LIB=$(DEBUG_NAME)$(STATIC_SUFFIX).$(STEXT)
STLDEBUG_LIB=$(STLDEBUG_NAME)$(STATIC_SUFFIX).$(STEXT)

ALL_STATIC_LIBS=$(OUTDIR)$(PATH_SEP)$(RELEASE_LIB) $(OUTDIR)$(PATH_SEP)$(DEBUG_LIB) $(OUTDIR)$(PATH_SEP)$(STLDEBUG_LIB)

ALL_DYNAMIC_LIBS=$(OUTDIR)$(PATH_SEP)$(RELEASE_DYNLIB) $(OUTDIR)$(PATH_SEP)$(DEBUG_DYNLIB) $(OUTDIR)$(PATH_SEP)$(STLDEBUG_DYNLIB)

RELEASE_OBJECTS_static= \
$(RELEASE_OBJDIR_static)$(PATH_SEP)complex.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)complex_io.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)dll_main.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)range_errors.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)string.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ios_base.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ios.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)streambuf.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)iostream.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)fstream.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)strstream.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)sstream.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)c_locale.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)codecvt.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)collate.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ctype.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)locale.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)message_facets.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)monetary.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)money_get.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)money_put.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_get.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_put.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)numpunct.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)time_facets.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)time_get.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)time_put.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)string_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)collate_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)ios_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(RELEASE_OBJDIR_static)$(PATH_SEP)time_put_w.$(OBJEXT)



DEBUG_OBJECTS_static= \
$(DEBUG_OBJDIR_static)$(PATH_SEP)dll_main.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)range_errors.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)string.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ios_base.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ios.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)streambuf.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)iostream.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)fstream.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)strstream.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)sstream.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)c_locale.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)codecvt.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)collate.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)complex.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)complex_io.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ctype.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)locale.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)message_facets.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)monetary.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)money_get.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)money_put.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_get.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_put.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)numpunct.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)time_facets.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)time_get.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)time_put.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)collate_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)ios_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)string_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(DEBUG_OBJDIR_static)$(PATH_SEP)time_put_w.$(OBJEXT)



STLDEBUG_OBJECTS_static= \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)dll_main.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)range_errors.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)string.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ios_base.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ios.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)streambuf.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)iostream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)fstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)strstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)sstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)c_locale.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)codecvt.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)collate.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)complex.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)complex_io.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ctype.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)locale.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)message_facets.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)monetary.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)money_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)money_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)numpunct.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)time_facets.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)time_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)time_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)string_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)collate_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)ios_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_static)$(PATH_SEP)time_put_w.$(OBJEXT)

###########################################################

RELEASE_OBJECTS_dynamic= \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)dll_main.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)range_errors.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)string.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ios_base.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ios.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)streambuf.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)iostream.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)fstream.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)strstream.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)sstream.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)c_locale.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)codecvt.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)collate.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)complex.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)complex_io.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ctype.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)locale.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)message_facets.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)monetary.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)money_get.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)money_put.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_get.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_put.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)numpunct.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)time_facets.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)time_get.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)time_put.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)collate_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)ios_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)string_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(RELEASE_OBJDIR_dynamic)$(PATH_SEP)time_put_w.$(OBJEXT) \
$(RESFILE)

DEBUG_OBJECTS_dynamic= \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)dll_main.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)range_errors.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)string.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ios_base.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ios.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)streambuf.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)iostream.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)fstream.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)strstream.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)sstream.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)c_locale.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)collate.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)complex.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_io.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)locale.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)message_facets.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)monetary.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)money_get.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)money_put.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)time_facets.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)time_get.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)time_put.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)ios_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)string_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(DEBUG_OBJDIR_dynamic)$(PATH_SEP)time_put_w.$(OBJEXT) \
$(RESFILE_debug)


STLDEBUG_OBJECTS_dynamic= \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)dll_main.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)range_errors.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)string.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ios_base.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ios.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)streambuf.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)stdio_streambuf.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)iostream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)fstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)strstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)sstream.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)c_locale.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)c_locale_stub.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)collate.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)complex.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_exp.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_io.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_trig.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)locale.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)locale_catalog.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)locale_impl.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)message_facets.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)monetary.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)money_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)money_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_float.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_inst.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_float.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_inst.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct_byname.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)time_facets.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)time_get.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)time_put.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)complex_io_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)fstream_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)codecvt_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)collate_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ctype_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)ios_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)message_facets_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)money_get_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)money_put_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_byname_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)moneypunct_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_get_inst_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)num_put_inst_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)numpunct_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)string_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)time_get_w.$(OBJEXT) \
$(STLDEBUG_OBJDIR_dynamic)$(PATH_SEP)time_put_w.$(OBJEXT) \
$(RESFILE_stldebug)



