//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//March 10, 2018
//Binary Search Tree implementation of the Dictionary ADT

public class Dictionary implements DictionaryInterface {
  private class Node {
    String key;
    String value;
    Node left;
    Node right;
    Node(String key, String val) {
      this.key = key;
      this.value = val;
    }
  }

  private Node root;
  private int numItems;
  public Dictionary() {
    root = null;
    numItems = 0;
  }

  public Node findKey(Node R, String k) {
    if(R == null || k.compareTo(R.key) == 0) {
      return R;
    }
    if(k.compareTo(R.key) < 0) {
      return findKey(R.left, k);
    }
    else {
      return findKey(R.right, k);
    }
  }

  public Node findParent(Node N, Node R) {
    Node P = null;
    if(N != R) {
      P = R;
      while(P.left != N && P.right != N) {
        if(N.key.compareToIgnoreCase(P.key) < 0) {
          P = P.left;
        }
        else {
          P = P.right;
        }
      }
    }
    return P;
  }

  public Node findLeftmost(Node R) {
    Node L = R;
    if(L != null) {
      for(int i = 0; L.left != null; i++);
    }
    return L;
  }

  public void printInOrder(Node R) {
    if (R != null) {
      printInOrder(R.left);
      System.out.println(R.key + " " + R.value);
      printInOrder(R.right);
    }
  }

  public void deleteAll() {
    root = null;
    numItems = 0;
  }

  public boolean isEmpty() {
    return (numItems == 0);
  }

  public int size() {
    return numItems;
  }

  public String lookup(String key) {
    Node N = findKey(root, key);
    if(N != null) {
      return N.value;
    }
    else {
      return null;
    }
  }

  public void insert(String key, String value) throws DuplicateKeyException {
    Node N = new Node(key, value);
    Node A = root;
    Node B = null;
    if(findKey(root, key) != null) {
      throw new DuplicateKeyException("Dictionary Error: insert() cannot insert duplicate key: " + key);
    }
    while(A != null) {
      B = A;
      if(key.compareTo(A.key) > 0) {
        A = A.right;
      }
      else {
        A = A.right;
      }
    }
    if(B == null) {
      root = N;
    }
    else if(key.compareTo(B.key) < 0) {
      B.left = N;
    }
    else {
      B.right = N;
    }
    numItems++;
  }

  public void delete(String key) throws KeyNotFoundException {
    Node N = findKey(root, key);
    Node P, S;
    if(findKey(root, key) == null) {
      throw new KeyNotFoundException("Dictionary Error: delete() cannot delete non-existent key: " + key);
    }
    if(N.left == null && N.right == null) {
      if(N == root) {
        root = null;
      }
      else {
        P = findParent(N, root);
        if(P.right == N) {
          P.right = null;
        }
        else {
          P.left = null;
        }
      }
    }
    else if(N.right == null) {
      if(N == root) {
        root = N.left;
      }
      else {
        P = findParent(N, root);
        if(P.right == N) {
          P.right = N.left;
        }
        else {
          P.left = N.left;
        }
      }
    }
    else if(N.left == null) {
      if(N == root) {
        root = N.right;
      }
      else {
        P = findParent(N, root);
        if(P.right == N) {
          P.right = N.right;
        }
        else {
          P.left = N.right;
        }
      }
    }
    else {
      S = findLeftmost(N.right);
      N.key = S.key;
      N.value = S.value;
      P = findParent(S, N);
      if(P.right == S) {
        P.right = S.right;
      }
      else {
        P.left = S.right;
      }
    }
    numItems--;
  }

  public void makeEmpty() {
    deleteAll();
    root = null;
    numItems = 0;
  }

  public String toString() {
    printInOrder(root);
    return "";
  }


}
