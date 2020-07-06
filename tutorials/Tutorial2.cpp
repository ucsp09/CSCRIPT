//A simple Navigation Bar using cscript
#include "cscript.hpp"
#include <iostream>
int main()
{
    try{
        html::Element root("html");
        html::Element navbar("div",{{"class","navbar"}},"");
        html::Element left("div",{{"class","left"},{"style","float:left;"}},"");
        html::Element right("div",{{"class","right"},{"style","float:right;"}},"");
        html::Element link1("a",{{"id","#null"}},"Home");
        html::Element link2,link3,link4,link5;
        link1.clone(link2,true);
        link1.clone(link3,true);
        link1.clone(link4,true);
        link1.clone(link5,true);
        link2.set_text("About");
        link3.set_text("Contact");
        link4.set_text("Login");
        link5.set_text("Signup");
        left.append_child(link1);
        left.append_child(link2);
        left.append_child(link3);
        right.append_child(link4);
        right.append_child(link5);
        navbar.append_child(left);
        navbar.append_child(right);
        root.append_child(navbar);
        std::cout<<root.to_html();
        root.dump("test");
    }
    catch(std::exception& e){
        std::cout<<"\n"<<e.what();
    }
    return 0;
}