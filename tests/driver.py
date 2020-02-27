#!/usr/bin/env python3
import sys, os
import uuid
import glob

###############################################################################
#
# If the first parameter is a directory, then run all of the tests in that
# directory. If the first parameter is a file, then just run the test for
# that file.
#
# A test consists of a comment block that gives what the test prints out
# from the DBG output. The first line of the comment is the name of the
# test that will be printed out when the test is run.
#
# The comment is written out as a temporary file, then the test file is
# compiled and run using toi. Then the output of the run is compared to
# the contents of the comment. If they match, then the test passes. If
# they do not match, then the test fails and the line number is printed
# out.
#
###############################################################################

def check_result(result, proof):
    # Compare the result and proof files, line by line and count up the
    # differences. Return that number.
    res_lines = []
    with open(result, 'r') as fp:
        for line in fp:
            ll = line.strip().split()
            res_lines.append(" ".join(ll[2:]))
    #print(res_lines)

    pro_lines = []
    with open(proof, 'r') as fp:
        for line in fp:
            ll = line.strip().split()
            pro_lines.append(" ".join(ll[2:]))
    #print(pro_lines)

    errors = 0
    if len(pro_lines) != len(res_lines):
        errors += 1
        sys.stdout.write("FAIL: number of lines does not match.\n")
        return

    miscompare_list = []
    for idx in range(len(res_lines)):
        if res_lines[idx] != pro_lines[idx]:
            errors += 1
            miscompare_list.append(idx+1)

    if errors != 0:
        print("FAIL: miscompared lines:")
        print("    ", miscompare_list)
    else:
        print("PASS")


def build_test(name, outfile):
    # spawn the compiler on the test file name and save the results in a
    # temporary file. If the compile fails to spawn then return None.
    os.system('../toi %s > %s'%(name, outfile))


def run_test(tname, pname):

    #with open(name, 'r') as infp:
    #(tname, proof_file) = write_proof(name)
    sys.stdout.write("    Name: %s - "%(tname))
    outfp_name = "%s.tmp"%(str(uuid.uuid4()))
    build_test(tname, outfp_name)
    check_result(outfp_name, pname)

    #os.unlink(proof_file)
    os.unlink(outfp_name)

if __name__ == '__main__':
    try:
        name = sys.argv[1]
    except:
        print("\nAt least one arg is required. The arg")
        print("can be a file name or a directory name.\n")
        exit(1)

    try:
        test_names = []
        for item in sys.argv[1:]:
            test_names.append(os.path.abspath(item))
    except:
        pass

    test_list = []
    proof_list = []
    for item in test_names:
        if os.path.isdir(item):
            full_name = os.path.abspath(item)
            names = glob.glob(os.path.join(full_name, '*.toi'))
            #names = os.listdir(full_name)
            for name in names:
                fname = os.path.join(full_name, name)
                test_list.append(fname)
                proof_list.append(fname.replace('.toi', '.proof'))
        else:
            fname = os.path.abspath(item)
            test_list.append(fname)
            proof_list.append(fname.replace('.toi', '.proof'))

    print("\nList of test files:")
    for name in test_list:
        print("    %s"%(name))

    print("\nRunning tests:")
    #for name in test_list:
    for idx in range(len(test_list)):
        if not os.path.isfile(proof_list[idx]):
            build_test(test_list[idx], proof_list[idx])
            print("    Init proof file: %s"%(proof_list[idx]))
        else:
            run_test(test_list[idx], proof_list[idx])

    print("\n")


# def write_proof(name):
#     # Open the input file and write the proof data to a temporary file.
#     infp = open(name, 'r')
#     lines = infp.readlines()
#     infp.close()

#     # Create a temporary file to put the proof into. Returns the temp file
#     # name so that it can be deleted by the run_test() function.
#     outfp_name = "%s.tmp"%(str(uuid.uuid4()))
#     outfp = open(outfp_name, 'w')

#     # skip white space until a "/*" is found as a single string on an otherwise
#     # blank line.
#     for idx in range(len(lines)):
#     #for line in lines:
#         line = lines[idx].strip()
#         if line == '/*':
#             break

#     idx += 1
#     # Read and write the lines to the temp file until a "*/" string is found
#     # on a single line with no other characters.
#     #test_name = infp.readline().strip()
#     end_found = False
#     test_name = lines[idx].strip()
#     for line in lines[idx+1:]:
#         line = line.strip()
#         if line == '*/':
#             end_found = True
#             break
#         else:
#             outfp.write("%s\n"%(line))

#     if not end_found:
#         print("ERROR: Test appears to be malformed.")
#         outfp.close()
#         exit(1)

#     outfp.close()
#     return (test_name, outfp_name)
