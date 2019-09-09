
do_install: all
	@echo Copying STLport DLLs to Windows system directory...
	@if "%OS%" == "Windows_NT" copy $(OUTDIR)\$(LIB_BASENAME)*.dll $(WINDIR)\System32
	@if "%OS%" == "" copy $(OUTDIR)\$(LIB_BASENAME)*.dll $(WINDIR)\System
	@echo STLport DLL libraries are installed on your system.

#	if not exist "$(OUTDIR)/$(NULL)" $(MKDIR) "$(OUTDIR)"

{$(SRCDIR)}.cpp{$(RELEASE_OBJDIR_static)}.obj:
   $(CXX) $(CXXFLAGS_RELEASE_static) $< 

{$(SRCDIR)}.c{$(RELEASE_OBJDIR_static)}.obj:
   $(CC) $(CXXFLAGS_RELEASE_static) $< 

{$(SRCDIR)}.c{$(RELEASE_OBJDIR_static)}.sbr:
   $(CC) $(CXXFLAGS_RELEASE_static) $< 

{$(SRCDIR)}.cpp{$(RELEASE_OBJDIR_static)}.sbr:
   $(CXX) $(CXXFLAGS_RELEASE_static) $<


{$(SRCDIR)}.cpp{$(RELEASE_OBJDIR_dynamic)}.obj:
   $(CXX) $(CXXFLAGS_RELEASE_dynamic) $< 

{$(SRCDIR)}.c{$(RELEASE_OBJDIR_dynamic)}.obj:
   $(CC) $(CXXFLAGS_RELEASE_dynamic) $< 

{$(SRCDIR)}.c{$(RELEASE_OBJDIR_dynamic)}.sbr:
   $(CC) $(CXXFLAGS_RELEASE_dynamic) $< 

{$(SRCDIR)}.cpp{$(RELEASE_OBJDIR_dynamic)}.sbr:
   $(CXX) $(CXXFLAGS_RELEASE_dynamic) $<

#########################################

{$(SRCDIR)}.cpp{$(DEBUG_OBJDIR_static)}.obj:
   $(CXX) $(CXXFLAGS_DEBUG_static) $<

{$(SRCDIR)}.c{$(DEBUG_OBJDIR_static)}.obj:
   $(CC) $(CXXFLAGS_DEBUG_static) $<

{$(SRCDIR)}.c{$(DEBUG_OBJDIR_static)}.sbr:
   $(CC) $(CXXFLAGS_DEBUG_static) $<

{$(SRCDIR)}.cpp{$(DEBUG_OBJDIR_static)}.sbr:
   $(CXX) $(CXXFLAGS_DEBUG_static) $<

{$(SRCDIR)}.cpp{$(DEBUG_OBJDIR_dynamic)}.obj:
   $(CXX) $(CXXFLAGS_DEBUG_dynamic) $<

{$(SRCDIR)}.c{$(DEBUG_OBJDIR_dynamic)}.obj:
   $(CC) $(CXXFLAGS_DEBUG_dynamic) $<

{$(SRCDIR)}.c{$(DEBUG_OBJDIR_dynamic)}.sbr:
   $(CC) $(CXXFLAGS_DEBUG_dynamic) $<

{$(SRCDIR)}.cpp{$(DEBUG_OBJDIR_dynamic)}.sbr:
   $(CXX) $(CXXFLAGS_DEBUG_dynamic) $<

######################################### 

{$(SRCDIR)}.cpp{$(STLDEBUG_OBJDIR_static)}.obj:
   $(CXX) $(CXXFLAGS_STLDEBUG_static) $<

{$(SRCDIR)}.c{$(STLDEBUG_OBJDIR_static)}.obj:
   $(CC) $(CXXFLAGS_STLDEBUG_static) $<

{$(SRCDIR)}.c{$(STLDEBUG_OBJDIR_static)}.sbr:
   $(CC) $(CXXFLAGS_STLDEBUG_static) $<

{$(SRCDIR)}.cpp{$(STLDEBUG_OBJDIR_static)}.sbr:
   $(CXX) $(CXXFLAGS_STLDEBUG_static) $<

{$(SRCDIR)}.cpp{$(STLDEBUG_OBJDIR_dynamic)}.obj:
   $(CXX) $(CXXFLAGS_STLDEBUG_dynamic) $<

{$(SRCDIR)}.c{$(STLDEBUG_OBJDIR_dynamic)}.obj:
   $(CC) $(CXXFLAGS_STLDEBUG_dynamic) $<

{$(SRCDIR)}.c{$(STLDEBUG_OBJDIR_dynamic)}.sbr:
   $(CC) $(CXXFLAGS_STLDEBUG_dynamic) $<

{$(SRCDIR)}.cpp{$(STLDEBUG_OBJDIR_dynamic)}.sbr:
   $(CXX) $(CXXFLAGS_STLDEBUG_dynamic) $<

############################################

{$(SRCDIR)}.rc{$(RELEASE_OBJDIR_dynamic)}.res:
	$(RC) /d COMP=$(COMP) /fo $(RELEASE_OBJDIR_dynamic)\stlport.res $<

{$(SRCDIR)}.rc{$(DEBUG_OBJDIR_dynamic)}.res:
	$(RC) /d COMP=$(COMP) /d BUILD=DEBUG /fo $(DEBUG_OBJDIR_dynamic)\stlport.res $<

{$(SRCDIR)}.rc{$(STLDEBUG_OBJDIR_dynamic)}.res:
	$(RC) /d COMP=$(COMP) /d BUILD=STLDEBUG /fo $(STLDEBUG_OBJDIR_dynamic)\stlport.res $<

