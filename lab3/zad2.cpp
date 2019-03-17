#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <cmath>
#include <utility>
#include <iomanip>



struct SmartTree {
    int data;

    std::unique_ptr<SmartTree> left = nullptr;
    std::unique_ptr<SmartTree> right = nullptr;
};


std::unique_ptr <SmartTree> CreateLeaf(int value);

std::unique_ptr <SmartTree>& InsertLeftChild(std::unique_ptr<SmartTree> &tree, std::unique_ptr<SmartTree> left_subtree);
std::unique_ptr <SmartTree>& InsertRightChild(std::unique_ptr<SmartTree> &tree, std::unique_ptr<SmartTree> right_subtree);

void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
void PrintTreePreOrder(const std::unique_ptr<SmartTree> &unique_ptr,std::ostream *out);

std::string DumpTreeInOrder(const std::unique_ptr<SmartTree> &tree);
std::string DumpTreePreOrder(const std::unique_ptr<SmartTree> &tree);


std::unique_ptr<SmartTree> BuildTree(const std::vector<int>& vIn ,const std::vector<int>& vPre, int inS , int inE );
std::unique_ptr<SmartTree> RestoreTree(const std::string& sIn ,const std::string& sPre);


std::vector<int> SplitStringToVector(std::string str , char sep);


/*
    ||\\   //||     //\\    ||   ||\\   ||
    ||  \\// ||   || ___||  ||   || \\  ||
    ||       ||   ||    ||  ||   ||  \\ ||
    ||       ||   ||    ||  ||   ||   \\||
*/



int main(int argc , char** argv ){

    std::unique_ptr<SmartTree> tree = CreateLeaf(1);

    std::unique_ptr<SmartTree> &left = InsertLeftChild(tree, CreateLeaf(2));
    std::unique_ptr<SmartTree> &right = InsertRightChild(tree, CreateLeaf(3));

    InsertLeftChild(left, CreateLeaf(4));
    InsertRightChild(left, CreateLeaf(5));
    InsertLeftChild(right, CreateLeaf(6));
    InsertRightChild(right, CreateLeaf(7));
/*
            1
         /    \
        2      3
      /  \    /  \
     4   5   6    7
*/




    auto new_tree = RestoreTree(DumpTreeInOrder(tree) , DumpTreePreOrder(tree));


    auto inorder = DumpTreeInOrder(new_tree);
    std::cout << inorder << '\n';




    return 0;
}

/*
    ||====  ||   ||  ||\\   ||   //===
    ||      ||   ||  || \\  ||  ||
    ||====  ||   ||  ||  \\ ||  ||
    ||      \\===//  ||   \\||  \\===
*/

std::unique_ptr <SmartTree> CreateLeaf(int value){

    std::unique_ptr<SmartTree> tree = std::make_unique<SmartTree>();

    tree-> data = value;
    tree-> left = nullptr;
    tree-> right = nullptr;

    return std::move(tree);
}

std::unique_ptr <SmartTree>& InsertLeftChild(std::unique_ptr<SmartTree> &tree, std::unique_ptr<SmartTree> left_subtree){

    tree->left = std::move(left_subtree);
    return tree->left;
}

std::unique_ptr <SmartTree>& InsertRightChild(std::unique_ptr<SmartTree> &tree, std::unique_ptr<SmartTree> right_subtree){

    tree->right = std::move(right_subtree);
    return tree->right;
}

void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr,std::ostream *out){

    if(unique_ptr == nullptr) return ; // if ptr is null - break

    PrintTreeInOrder(std::move(unique_ptr -> left), out);
    *out << unique_ptr -> data << " ";
    PrintTreeInOrder(std::move(unique_ptr -> right), out);
}

void PrintTreePreOrder(const std::unique_ptr<SmartTree> &unique_ptr,std::ostream *out){
    if(unique_ptr == nullptr) return ;

    *out << unique_ptr -> data << " ";
    PrintTreeInOrder(std::move(unique_ptr -> left), out);
    PrintTreeInOrder(std::move(unique_ptr -> right), out);
}

std::string DumpTreeInOrder(const std::unique_ptr<SmartTree> &tree){
    // convert tree -> string  in order tree
    std::ostringstream oss;
    PrintTreeInOrder(std::move(tree), &oss);

    return oss.str();
}

std::string DumpTreePreOrder(const std::unique_ptr<SmartTree> &tree){
    // convert tree -> string  pre order tree
    std::ostringstream oss;
    PrintTreePreOrder(std::move(tree), &oss);

    return oss.str();
}



std::unique_ptr<SmartTree> BuildTree(const std::vector<int>& vIn ,const std::vector<int>& vPre, int inS , int inE ){

    static int preIndex = 0;

    if(inS > inE) return nullptr;

    auto tree = CreateLeaf(vPre[preIndex++]);

    if(inS == inE ) return tree;

    int target = tree -> data;
    int inIndex = 0;
    for(auto& x: vIn){
        if(x == target){
            break;
        }
        inIndex++;
    }

    InsertLeftChild(tree,BuildTree(vIn , vPre , inS , inIndex - 1));
    InsertRightChild(tree,BuildTree(vIn , vPre , inIndex + 1 , inE));

    return std::move(tree);
}

std::unique_ptr<SmartTree> RestoreTree(const std::string& sIn ,const std::string& sPre){
    std::vector<int> vIn = SplitStringToVector(sIn , ' ');
    std::vector<int> vPre = SplitStringToVector(sPre , ' ');
    std::unique_ptr<SmartTree> tree = BuildTree(vIn,vPre,0 , vIn.size() -1);
    return std::move(tree);
}

std::vector<int> SplitStringToVector(std::string str , char sep){
    std::vector<int> result;
    std::string buff ="";

    for(auto c: str){
        if(c != sep){
            buff += c;
        } else {
            result.push_back(std::stoi(buff));
            buff = "";
        }
    }
    return result;
}
