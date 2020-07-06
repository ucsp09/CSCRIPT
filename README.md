# CSCRIPT
A C++ library adopting the HTML DOM(Document Object Model) to write html documents efficiently.
# BUILDING
For use in a project simply copy all the files present in lib folder to your workspace folder.
# USAGE
Following is a simple example depicting the things you can do with this library.
    
    html::Element obj1("html");                                                               Sample.html & Output
    html::Element obj2("p");                                                                  <html>
    html::Element obj3("p","This is a Sample Paragraph");                                     <p></p>
    html::Element obj4("p",{{"style","color:red;"}},"This is a Sample Paragraph");            <p>
    html::Element obj5,obj6;                                                                  This is a Sample Paragraph
    obj4.clone(obj5,true);                                                                    </p>
    obj4.clone(obj6,true);                                                                    <p style="color:red">    
    obj5.set_attribute("style","color:blue;");                                                This is a Sample Paragraph
    obj6.set_attribute("style","color:green;");                                               </p>  
    obj1.append_child(obj2);                                                                  <p style="color:blue">    
    obj1.append_child(obj3);                                                                  This is a Sample Paragraph
    obj1.append_child(obj4);                                                                  </p>
    obj1.append_child(obj5);                                                                  <p style="color:green;">
    obj1.append_child(obj6);                                                                  This is a Sample Paragraph
    std::cout<<obj1.to_html();                                                                </p>  
    obj1.dump("sample");                                                                      </html> 
## Namespace
All Classes are defined inside the namespace html. So, use html::classname to use the class. However, you can also use 'using namespace html;' in your source file.
## Element Class
This is the main class present in the namespace html. Every component of a html document is considered to be of type Element.
### Named Elements(Valid State Elements)
A named Element is one which is constructed using any of the given below methods:
  
    Method-1.html::Element obj("p");
    Method-2.html::Element obj("p","This is a Sample Paragraph");
    Method-3.html::Element obj("p",{{"id","demo"},{"style","color:red;"}},"This is a smaple paragraph");
    
    Method-1 will create an object with <p></p> structure.
    Method-2 will create an object with <p>This is a Sample Paragraph</p> structure.
    Method-3 will create an object with <p id="demo" style="color:red;">This is a Sample Paragraph</p> structure.
### UnNamed Elements(InValid State Elements)(Used for Cloning)
An UnNamed Element is one which is constructed as follows:

    html::Element obj; 
    obj has no element name and is in an invalid state. However you can make it a namedElement as shown below:
        obj.rename_element("p");
    Now obj is named and is in a valid state with <p></p> structure.
# API
For the details of all the classes and methods refer to the api.pdf present in api folder.
# Tutorial
Tutorials are presented in the tutorials section to get you started.
# Future Versions
This is the version 1.1 of the cscript library.
Future Versions will include:
1. Methods to parsehtml files and obtain Element type objects.
2. Methods to access elements by className,TagName,IdName..etc.
3. Methods to addEvents to Elements.
3. A cscript to javascript transpiler.
