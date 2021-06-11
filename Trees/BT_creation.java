import java.util.*;
public class BT_creation{
    static Scanner sc = null;

    public static void main(String[] args){
        sc = new Scanner(System.in);
        Node root=createTree();

    }

    static Node createTree(){
        Node root = null;
        System.out.println("Enter data: ");
        int data = sc.nextInt();

        if(data==-1){
            return null;
        }
        root = new Node(data);

        System.out.println("Enter left for "+data);
        root.left = createTree();

        System.out.println("Enter right for "+data);
        root.right = createTree();

        return root;
    }
}

    class Node{
        Node left,right;
        int data;

        public Node(int data){
            this.data = data;
        }
    }

