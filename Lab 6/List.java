//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//March 5, 2018
// Linked list of an ADT list

@SuppressWarnings("overrides")
public class List<T> implements ListInterface<T> {
  private class Node {
    T item;
    Node next;

    Node(T x) {
      item = x;
      next = null;
    }
  }

  private Node head;
  private int numItems;

  public List() {
    head = null;
    numItems = 0;
  }

  private Node find(int index) {
    Node N = head;
    for(int i = 0; i < index - 1; i++) {
      N = N.next;
    }
    return N;
  }

  public boolean isEmpty() {
    return(numItems == 0);
  }

  public int size() {
    return numItems;
  }

  public T get(int index) throws ListIndexOutOfBoundsException {
    if(index < 1 || index > (numItems + 1)) {
      throw new ListIndexOutOfBoundsException("get(): invalid index: " + index);
    }
    Node N = find(index);
    return N.item;
  }

  public void add(int index, T newItem) throws ListIndexOutOfBoundsException {
    if(index < 1 || index > (numItems + 1)) {
      throw new ListIndexOutOfBoundsException("add(): invalid index: " + index);
    }
    if(index != 1) {
      Node A = find(index - 1);
      Node B = A.next;
      A.next = new Node(newItem);
      A = A.next;
      A.next = B;
    }
    else {
      Node N = new Node(newItem);
      N.next = head;
      head = N;
    }
    numItems++;
  }

  public void remove(int index) throws ListIndexOutOfBoundsException {
    if(index < 1 || index > (numItems + 1)) {
      throw new ListIndexOutOfBoundsException("remove(): invalid index: " + index);
    }
    if(index != 1) {
      Node A = find(index - 1);
      Node B = A.next;
      A.next = B.next;
      B.next = null;
    }
    else {
      Node N = head;
      head = head.next;
      N.next = null;
    }
    numItems--;
  }

  public void removeAll() {
    head = null;
    numItems = 0;
  }

  public String toString() {
    String S = "";
    for(Node N = head; N != null; N = N.next) {
      S += N.item.toString() + " ";
    }
    return S;
  }

  @SuppressWarnings("unchecked")
  public boolean equals(Object rhs) {
    boolean eq = false;
    List<T> R = null;
    Node N = null;
    Node M = null;

    if(this.getClass() == rhs.getClass()) {
      R = (List<T>)rhs;
      eq = (this.numItems == R.numItems);
      N = this.head;
      M = R.head;
      while(eq && (N != null)) {
        eq = (N.item == M.item);
        N = N.next;
        M = M.next;
      }
    }
    return eq;
  }

}
