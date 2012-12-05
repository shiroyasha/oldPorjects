#!/usr/bin/env python

import distutils.sysconfig
import os, sys

def check_value(value):

    if not value:
        sys.stderr.write("Invalid setting: %s\n" % sys.argv[1])
        sys.exit(1)

if __name__ == "__main__":

    if len(sys.argv) != 2:
    
        sys.stderr.write("Usage: %s <setting>\n" % sys.argv[0])
        sys.exit(1)
    
    elif sys.argv[1] == "site-packages":
    
        library_path = distutils.sysconfig.get_config_var("LIBP")
        check_value(library_path)
        value = os.path.join(library_path, "site-packages")
    
    else:
    
        value = distutils.sysconfig.get_config_var(sys.argv[1])
        check_value(value)
    
    print value
    sys.exit(0)
