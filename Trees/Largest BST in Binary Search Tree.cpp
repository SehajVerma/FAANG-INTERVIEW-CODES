https://www.youtube.com/watch?v=4fiDs7CCxkc


class MinMax
{
public:
    bool isBst;
    int size;
    int minx;
    int maxx;
    MinMax()
    {
        isBst=true;
        size=0;
        minx=INT_MAX;   //yaad rakho
        maxx=INT_MIN;   //yaad rakho
    }
};
MinMax largest(Node* root)
{
    if(root==NULL){
        MinMax m;
        return m;
    }
	MinMax leftTree = largest(root->left);
	MinMax rightTree = largest(root->right);
	
	MinMax m;
	
	if(leftTree.isBst ==false ||  rightTree.isBst ==false ||
	     leftTree.maxx >= root->data || rightTree.minx <= root->data)
	{
	    m.isBst = false;
	    m.size = max(leftTree.size,rightTree.size);
	    return m;
	}
	
	m.isBst = true;
	m.size = leftTree.size + rightTree.size + 1;
	
	m.minx = root->left!=NULL ? leftTree.minx : root->data;
	m.maxx = root->right!=NULL? rightTree.maxx: root->data;
	
	return m;
}
int largestBst(Node* root)
{
    MinMax m = largest(root);
    return m.size;
}
