# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.sna.Debug:
/Users/alligilbreath/Desktop/project9/project_9_example/bld/Debug/sna:
	/bin/rm -f /Users/alligilbreath/Desktop/project9/project_9_example/bld/Debug/sna


PostBuild.sna.Release:
/Users/alligilbreath/Desktop/project9/project_9_example/bld/Release/sna:
	/bin/rm -f /Users/alligilbreath/Desktop/project9/project_9_example/bld/Release/sna


PostBuild.sna.MinSizeRel:
/Users/alligilbreath/Desktop/project9/project_9_example/bld/MinSizeRel/sna:
	/bin/rm -f /Users/alligilbreath/Desktop/project9/project_9_example/bld/MinSizeRel/sna


PostBuild.sna.RelWithDebInfo:
/Users/alligilbreath/Desktop/project9/project_9_example/bld/RelWithDebInfo/sna:
	/bin/rm -f /Users/alligilbreath/Desktop/project9/project_9_example/bld/RelWithDebInfo/sna




# For each target create a dummy ruleso the target does not have to exist
