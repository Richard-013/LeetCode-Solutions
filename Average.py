import os
import linecache

averageRuntimePercentage = 0
averageMemoryPercentage = 0

cppFiles = []

for rootDirectory, directoryNames, fileNames in os.walk("C:\\Users\\Richard\\Documents\\GitHub\\LeetCode-Solutions"):
    for file in fileNames:
        if file.endswith(".cpp"):
            cppFiles.append(os.path.join(rootDirectory, file))

for codeFile in cppFiles:
    runtimeLine = linecache.getline(codeFile, 5)
    memoryLine = linecache.getline(codeFile, 8)
    linecache.clearcache()

    if(runtimeLine[14] == '%'):
        averageRuntimePercentage = averageRuntimePercentage + float(runtimeLine[9:12])
    else:
        averageRuntimePercentage = averageRuntimePercentage + float(runtimeLine[9:13])
    
    if(memoryLine[14] == '%'):
        averageMemoryPercentage = averageMemoryPercentage + float(memoryLine[9:12])
    else:
        averageMemoryPercentage = averageMemoryPercentage + float(memoryLine[9:13])

averageRuntimePercentage = round(averageRuntimePercentage/len(cppFiles), 2)
averageMemoryPercentage = round(averageMemoryPercentage/len(cppFiles), 2)

readmeLines = []

with open("C:\\Users\\Richard\\Documents\\GitHub\\LeetCode-Solutions\\README.md", 'r') as readmeFile:
    readmeLines = readmeFile.readlines()

readmeLines[10] = "Average **Runtime** beats " + str(averageRuntimePercentage) + "% of other submissions.\n"
readmeLines[11] = "Average **Memory Usage** beats " + str(averageMemoryPercentage) + "% of other submissions.\n"

with open("C:\\Users\\Richard\\Documents\\GitHub\\LeetCode-Solutions\\README.md", 'w') as readmeFile:
    readmeFile.writelines(readmeLines)
