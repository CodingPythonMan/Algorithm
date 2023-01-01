using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class LeetCode938Service
    {
        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int val = 0, TreeNode left = null!, TreeNode right = null!)
            {
                this.val = val;
                this.left = left;
                this.right = right;
            }
        }
        int globalLow;
        int globalHigh;
        int result = 0;

        public int RangeSumBST(TreeNode root, int low, int high)
        {
            globalLow = low;
            globalHigh = high;
            inorder(root);
            return result;
        }

        public void inorder(TreeNode node)
        {
            if (node is not null)
            {
                inorder(node.left);
                visit(node);
                inorder(node.right);
            }
        }

        public void visit(TreeNode node)
        {
            if (globalLow <= node.val && globalHigh >= node.val)
            {
                result += node.val;
            }
        }
    }
}
