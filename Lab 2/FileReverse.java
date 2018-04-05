//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//January 20, 2018
//scans a txt file and converts it into strings and reverses the order of each inidivual string by characters

import java.io.*;
import java.util.Scanner;

public class FileReverse {
  public static void main(String[] args) throws IOException{
    Scanner in = null;
    PrintWriter out = null;
    String line = null;
    String[] token = null;
    int i, n, lineNumber = 0;
    //check number of command line arguments is at least 2
    if(args.length < 2) {
      System.out.println("Usage: FileCopy <input file> <output file>");
      System.exit(1);
    }
    //opens files
    in = new Scanner(new File(args[0]));
    out = new PrintWriter(new File(args[1]));
    //read lines from in, write lines to out
    while(in.hasNextLine()) {
      lineNumber++;
      //trim leading and trailing spaces,
      //then add one trailing space so
      //split works on blank lines
      line = in.nextLine().trim() + " ";
      //split line around white space
      token = line.split("\\s+");
      //print out tokens
      n = token.length;
      for(i = 0; i < n; i++) {
        out.println(stringReverse(token[i], token[i].length()));
      }
    }
    //close FileReverse
    in.close();
    out.close();
  }

  //recursive method to reverse the order of the string
  public static String stringReverse(String s, int n) {
    //base case when String has 1 character
    if(s.length() == 1) {
      return s;
    }
    //prints each individual character of the string starting with the greatest index
    else {
      return (s.charAt(n-1) + stringReverse(s.substring(0, n-1), n-1));
      }
    }
}
