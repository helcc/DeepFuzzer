import sys, os, re

def structfind(struct, sourcecode, headerfolder):
    sourcecode = open(sourcecode, "r+")

    found = False

    parser(struct, sourcecode)

    if(headerfolder != ""):
        for filename in os.listdir(headerfolder):
            while(found == False):
                headerfile = open(filename, "r+")
                found = parser(struct, headerfile)

def parser(struct, file):
    newfile = open("cache/structure_info.txt", "w")

    target = "struct " + struct
    line = file.readline()
    while target not in line:
        line = file.readline()

    if target in line:
        #case of struct x {
        if '{' in line:
            structinfo = line
            structinfo = file.readline()
            while '}' not in structinfo:
                list = structinfo.split()
                text = list[0] + ": " + ''.join(list[1:]) + '\n'
                newfile.write(text)

                structinfo = file.readline()
        #case of struct x
        #{
        else:
            structinfo = file.readline()
            structinfo = file.readline()
            while '}' not in structinfo:
                list = structinfo.split()
                text = list[0] + ": " + ''.join(list[1:]) + '\n'
                newfile.write(text)

                structinfo = file.readline()

        file.close()
        newfile.close()
        return True

    file.close()
    newfile.close()
    return False



structfind('apev2_hdr_ftr', 'test/structtest.c', '')
