class Tree
{
    //Function to return list containing elements of left view of binary tree.
    ArrayList<Integer> leftView(Node root)
    {
      List<Integer> ls = new ArraysList<Integer>();
      leftview(root,ls,0);
      return ls;
    }
    
    public void leftview(Node curr,List<Integer> ls,int depth){
        if(curr==null){
            return;
        }
        if(depth==ls.size()){
            ls.add(curr.data);
        }
        leftview(curr.left,ls,depth+1);
        leftview(curr.right,ls,depth+1);
    }
    
    
}
