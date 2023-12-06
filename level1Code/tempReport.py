# code name: tempReport.py
# code by: Davis Farrow
#
# CPE 422 Project 1 part 6
# Python script that parses the feed data for the temperature sensor and prints out a report
# indicating the minimum, maximum, and average temperatures. Download and process your
# feed data. For testing purposes, a data file will be provided to you.

import sys
import csv

def main():
    with open(sys.argv[1], 'r') as infile:
        # initializations
        val = [];
        total_val = 0

        # iterate through rows. Each line is appended to a list called val. A line is a list containing all the field values.
        for row in csv.reader(infile): 
            val.append(row[1])
        
        # remove index with string 'value and initialize max and min temp values
        val.remove('value')
        max_val = val[0]
        min_val = val[0]

        # find max, min and sum of temp values
        for i in range(len(val)):
            if max_val < val[i]:
                max_val = val[i]
            if min_val > val[i]:
                min_val = val[i]
            total_val += float(val[i])

        # find average of temp values 
        element_count = len(val)
        average = total_val/element_count

        # print statements
        print("\n")
        print("     TEMPERATURE REPORT")
        print("maximum value from feed data: ", max_val)
        print("minimum value from feed data: ", min_val)
        print("average value from feed data: ", average)
        print("\n")

        # close file
        infile.close()

main()
