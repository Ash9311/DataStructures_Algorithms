static node mirrorify(node root){
  if(root==null){
    return null;
  }
  node mirror = new node(root.val);
  mirror.left = mirrorify(root.right);
  mirror.right = mirrorify(root.left);
  return mirror;
}
  
