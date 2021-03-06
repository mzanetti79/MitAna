#!/usr/bin/env python
#===================================================================================================
#
# Merge root files from a given datasets together.
#
#===================================================================================================
import sys, getopt, os, fnmatch, commands
import string

#===================================================================================================
def usage():
    print "\n" \
          "possible options are:                 \n" \
          "    --help                            \n" \
          "    --debug                           \n" \
          "    --Dataset=<dataset>               \n" \
          "    --Skim=< noskim | skim >          \n" \
          "    --InputPath=<myInputPath>         \n" \
          "    --OutputPath=<myOutputPath>       \n" \
          "    --FilenameHeader=<myFileHeader>   \n"

#===================================================================================================
def filesExist(path,filenameExpression):
    exists = False
    
    if not os.path.exists(path):
      return exists;
    
    for fileName in os.listdir(path):
        if fnmatch.fnmatch (fileName,filenameExpression):
            exists = True
    return exists

#===================================================================================================
# Merge Filesets
#===================================================================================================
def MergeFilesets(debug,dataset,skim,inputPath,outputPath,filenameHeader):

    # say what we try to do
    print " Merging files for dataset: " + dataset + " (skim: " + skim + ")"

    # create the output directory in case it is not yet there
    command              = 'mkdir -p ' + outputPath
    os.system(command)

    # output name
    outputMergedFilename = filenameHeader + '_' + dataset + '_' + skim + '.root'

    # input file pattern to create input list
    inputFilenameRegExp  = filenameHeader + '_' + dataset + '_' + skim + '_????.root'
    if (debug):
        print " Input file data pattern: " + inputFilenameRegExp

    command              = 'hadd -f7 ' + outputPath + outputMergedFilename \
                           + ' ' + inputPath + '/' + dataset + '/' \
                           + inputFilenameRegExp + ' >& ./merging.tmp'
        
    if (filesExist(inputPath+'/'+dataset,inputFilenameRegExp) == True):
        if (os.path.exists(outputPath+outputMergedFilename)):
            print " Warning: merged file already exists. It will be deleted.\n " + \
                  outputPath+outputMergedFilename
            os.system('rm ' + outputPath+outputMergedFilename)
        os.system(command)
    else:
        print " Warning: No files for dataset " + dataset + "\n at the location: " + inputPath \
              + '/' + dataset + '/' + inputFilenameRegExp

#===================================================================================================
# Main Program
#===================================================================================================
debug           = False
datasetListFile = ''
dataset         = ''
skim            = ''
inputPath       = ''
outputPath      = ''
filenameHeader  = ''
versionList     = list()
datasetNameList = list()
skimNameList    = list()

if len(sys.argv[1:]) < 1:
    print "Error: not enough parameters specified"
    usage()
    sys.exit()

try:
    opts, args = getopt.getopt(sys.argv[1:], "hi:o:f:d:s:",
                               ["InputPath=","OutputPath=","FilenameHeader=","Dataset=","Skim=",
                                "help","debug"])
    for o, a in opts:
        if o in   ("-h", "--help"):
            usage()
            sys.exit()
        if o in   ("--debug"):
            debug = True
        elif o in ("-i", "--InputPath"):
            inputPath = a + "/"
        elif o in ("-o", "--OutputPath"):
            outputPath = a + "/"
        elif o in ("-f", "--FilenameHeader"):
            filenameHeader = a
        elif o in ("-d", "--Dataset"):
            dataset = a
        elif o in ("-s", "--Skim"):
            skim = a
        else:
            usage()
            sys.exit()
except getopt.GetoptError:
    usage()
    sys.exit(2)

if (inputPath == ''):
    print "Error: No InputPath specified."
    sys.exit()

if (outputPath == ''):
    print "Error: No OutputPath specified."
    sys.exit()

if (filenameHeader == ''):
    print "Error: No FilenameHeader specified."
    sys.exit()

if (dataset == ''):
    print "Error: No Dataset specified."
    sys.exit()

if (skim == ''):
    print "Error: No Skim variable specified."
    sys.exit()

# Here is where it all happens
MergeFilesets(debug,dataset,skim,inputPath,outputPath,filenameHeader)
