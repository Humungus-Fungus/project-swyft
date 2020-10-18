##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Swyft
ConfigurationName      :=Debug
WorkspacePath          :=/home/humfung/Documents/NEA_Project_Swyft
ProjectPath            :=/home/humfung/Documents/NEA_Project_Swyft/Swyft
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Devarsh
Date                   :=18/10/20
CodeLitePath           :=/home/humfung/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Swyft.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Interface.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(ObjectSuffix) $(IntermediateDirectory)/Dijkstra.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Documents/NEA_Project_Swyft/Swyft/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Interface.cpp$(ObjectSuffix): Interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Interface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Interface.cpp$(DependSuffix) -MM Interface.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Documents/NEA_Project_Swyft/Swyft/Interface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Interface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Interface.cpp$(PreprocessSuffix): Interface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Interface.cpp$(PreprocessSuffix) Interface.cpp

$(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(ObjectSuffix): ../../../Pictures/TrafficTimings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(DependSuffix) -MM ../../../Pictures/TrafficTimings.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Pictures/TrafficTimings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(PreprocessSuffix): ../../../Pictures/TrafficTimings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Pictures_TrafficTimings.cpp$(PreprocessSuffix) ../../../Pictures/TrafficTimings.cpp

$(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(ObjectSuffix): ../../../Pictures/GenerateCostMatrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(DependSuffix) -MM ../../../Pictures/GenerateCostMatrix.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Pictures/GenerateCostMatrix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(PreprocessSuffix): ../../../Pictures/GenerateCostMatrix.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Pictures_GenerateCostMatrix.cpp$(PreprocessSuffix) ../../../Pictures/GenerateCostMatrix.cpp

$(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(ObjectSuffix): ../../../Pictures/FuelOverTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(DependSuffix) -MM ../../../Pictures/FuelOverTime.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Pictures/FuelOverTime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(PreprocessSuffix): ../../../Pictures/FuelOverTime.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Pictures_FuelOverTime.cpp$(PreprocessSuffix) ../../../Pictures/FuelOverTime.cpp

$(IntermediateDirectory)/Dijkstra.cpp$(ObjectSuffix): Dijkstra.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Dijkstra.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Dijkstra.cpp$(DependSuffix) -MM Dijkstra.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/humfung/Documents/NEA_Project_Swyft/Swyft/Dijkstra.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Dijkstra.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Dijkstra.cpp$(PreprocessSuffix): Dijkstra.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Dijkstra.cpp$(PreprocessSuffix) Dijkstra.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


