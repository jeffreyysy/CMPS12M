//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//March 5, 2018
//test file

public class ListTest {
  public static void main(String[] args) {
    List<String> A = new List<String>();
    List<String> B = new List<String>();
    List<List<String>> C = new List<List<String>>();

    A.add(1, "two");
    A.add(2, "four");
    A.add(3, "six");
    A.add(4, "eight");
    A.add(5, "ten");

    B.add(1, "one");
    B.add(2, "three");
    B.add(3, "five");
    B.add(4, "seven");
    B.add(5, "nine");

    C.add(1, A);
    C.add(1, B);

    System.out.println("A size: " + A.size()); //5
    System.out.println("B size: " + B.size()); //5
    System.out.println("C size: " + C.size()); //2
    System.out.println("A: " + A); // two four six eight ten
    System.out.println("B: " + B); // one three five seven nine
    System.out.println("C: " + C);// one three five seven nine  two four six eight ten

    System.out.println("A.equals(A) is "+A.equals(A)); //true
    System.out.println("A.equals(B) is "+A.equals(B)); //false
    System.out.println("A.equals(C) is "+A.equals(C)); //false

    A.remove(2);
    B.remove(5);

    System.out.println("A size: " + A.size()); //A size: 4
    System.out.println("B size: " + B.size()); //B size: 4

    System.out.println("A: " + A); //A: two six eight ten
    System.out.println("B: " + B); //B: one three five seven

    A.removeAll();
    B.removeAll();

    System.out.println("A size: " + A.size()); //A size: 0
    System.out.println("B size: " + B.size()); //B size: 0

    System.out.println("A: " + A); //A:
    System.out.println("B: " + B); //B:


  }

}
