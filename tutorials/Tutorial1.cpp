#include <iostream>
#include "cscript.hpp"

int main()
{
    try{
        /*
        Following is the tutorial on how to start using cscript.
        For Now execute the block1 by removing the comments.
        */
            /*//Block1
                html::Element obj1;  // this is an unnamed Element
                html::Element obj2; //this is an unnamed Element
                obj1.append_child(obj2); //this results in an exception
            *///Block1
            
        /*
        So Unnamed Elements cannot be used to call any of the functions available in html::Element class.
        The only method it can call is rename_element(std::string& name) which will convert it
        to a namedElement.
        Now after conversion , On this element we can call all the functions.
        Execute the Block2 by removing the comments.
        */
            /*//Block2
                html::Element obj1; // this is an unnamed Element
                html::Element obj2; // this is an unnamed Element
                obj1.rename_element("div"); //Now it is converted to a named Element
                obj2.rename_element("p");  //Now it is converted to a named Element
                obj1.append_child(obj2);  //this is legal 
            *///Block2
        /*
        So As you can see unnamed Elements seem to be of no use But they are useful when it comes to cloning.
        You can clone a particular namedElement only to an unnamed Element, otherwise an exception occurs.
        Execute the block3 by removing the comments.
        */
            /*//Block3
                html::Element obj1("div"); //this is a namedELement
                html::Element obj2("p","Hello World"); //this is a named Element
                obj1.append_child(obj2); // this creates <div><p>Hello World</p></div>
                html::Element obj3("div"); //this is a namedELement
                obj1.clone(obj3,true) // this results in an exception
            *///Block3
        /*
        As told earlier NamedELements cannot be used for cloning.So now unnamed Elements are useful here.
        Execute the block4 by removing the comments.
        */
            /*//Block4
                html::Element obj1("div"); //this is a namedELement
                html::Element obj2("p","Hello World"); //this is a named Element
                obj1.append_child(obj2); // this creates <div><p>Hello World</p></div>
                html::Element obj3; //this is an UnnamedELement
                obj1.clone(obj3,true) // this is legal
            *///Block4
        /*
        One last point before endiing this tutorial. Any element can only be in one position in the document.
        It cannot be in multiple positions thats the reason why you clone the elements to put them in 
        multiple posiitions.
        Execute the block5 by removing the comments.
        */
            /*//Block5
                html::Element obj1("html");
                html::Element obj2("h1");
                html::Element obj3("div");
                html::Element obj4("p");
                obj1.append_child(obj2);
                obj1.append_child(obj3);
                obj3.append_child(obj4);
                std::cout<<obj1.to_html(); //this outputs <html><h1></h1><div><p></p></div></html> 
                std::cout<<"\n After relocating";
                obj1.append_child(obj3);
                std::cout<<obj1.to_html();  //this outputs <html><h1></h1><div></div><p></p></html>
            *///Block5
        /*
        Thats's it this is the end of tutorial.Please look at the examples given in this folder for more clarity.
        */
    }
    catch(std::exception& e){
        std::cout<<"\n"<<e.what();
    }
    return 0;
}