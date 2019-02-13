using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the countingValleys function below.
    static int countingValleys(int n, string s) {
        int level = 0;
        bool inValley = false;
        bool inMountain = false;
        int valleys = 0;
        for (int i = 0; i < n; i++) {
            char direction = s[i];
            if (direction == 'D') {
                level--;                
            } else {
                level++;
            }
            if (level < 0) {
                inMountain = false;
                inValley = true;                    
            } else if (level > 0) {
                inMountain = true;
                inValley = false;
            } else {
                if (inValley) {
                    valleys++;
                }
                inValley = false;
                inMountain = false;
            }
        }
        return valleys;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine());

        string s = Console.ReadLine();

        int result = countingValleys(n, s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}

