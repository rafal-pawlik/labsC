#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <cmath>
#include <iomanip>



struct SmartTree {
    int data;

    std::unique_ptr<SmartTree> left = nullptr;
    std::unique_ptr<SmartTree> right = nullptr;
};


std::unique_ptr <SmartTree> CreateLeaf(int value);
std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
// std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

/*
    ||\\   //||     //\\    ||   ||\\   ||
    ||  \\// ||   || ___||  ||   || \\  ||
    ||       ||   ||    ||  ||   ||  \\ ||
    ||       ||   ||    ||  ||   ||   \\||
*/
int main(int argc , char** argv ){

    std::unique_ptr<SmartTree> tree = CreateLeaf(1);
    std::unique_ptr<SmartTree> left = CreateLeaf(2);
    std::unique_ptr<SmartTree> right = CreateLeaf(3);
    std::unique_ptr<SmartTree> leftleft = CreateLeaf(4);

    left = InsertLeftChild(std::move(left), std::move(leftleft));

    tree = InsertLeftChild(std::move(tree) , std::move(left));
    tree = InsertRightChild(std::move(tree) , std::move(right));

    std::cout << "Tree in order: " ;

    PrintTreeInOrder(tree , &std::cout);

    std::cout<< "\n" << DumpTree(tree) << "\n";



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

    return tree;
}

std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
    std::unique_ptr<SmartTree> new_tree = std::move(tree);
    new_tree -> left = std::move(left_subtree);

    return new_tree;
}

std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
    std::unique_ptr<SmartTree> new_tree = std::move(tree);
    new_tree -> right = std::move(right_subtree);

    return new_tree;
}

void PrintTreeInOrder(const std::unique_ptr<SmartTree>& unique_ptr,std::ostream *out){

    if(unique_ptr == nullptr) return ;

    PrintTreeInOrder(std::move(unique_ptr -> left), out);
    *out << unique_ptr -> data << ",";
    PrintTreeInOrder(std::move(unique_ptr -> right), out);
}

std::string DumpTree(const std::unique_ptr<SmartTree> &tree){

    std::ostringstream oss;

    PrintTreeInOrder(std::move(tree -> left), &oss);
    PrintTreeInOrder(std::move(tree -> right), &oss);

    return oss.str();
}
