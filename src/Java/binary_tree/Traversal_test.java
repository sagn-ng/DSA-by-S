package binary_tree;
import java.util.List;
public class Traversal_test {
    public static void main(String[] args) {
        TreeNode root=new TreeNode(12);
        root=new TreeNode(11, root, null);
        root=new TreeNode(10, root, null);

        root.right=new TreeNode(13);

        root=new TreeNode(3, null, root);

        root=new TreeNode(2, root, null);
        root.right=new TreeNode(4, null, new TreeNode(5));

        root=new TreeNode(1, root, null);

        TreeNode u=new TreeNode(6, new TreeNode(7), new TreeNode(9));
        root.right=u;
        List<Integer> result=postorder.postorderTraversal(root);
        System.out.println(result);
    }
}
