#ifndef _CSCRIPT_HPP
#define _CSCRIPT_HPP

#include <queue>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "errors.hpp"

namespace html{
    class Element{
        public: //constructors 
                Element()
                {
                    parentElement=firstChild=nextSibling=previousSibling=lastChild=nullptr;
                    alloced=false;
                }
                Element(const std::string &_elementName)
                {
                    if(_elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    elementName=_elementName;
                    parentElement=firstChild=nextSibling=previousSibling=lastChild=nullptr;
                    alloced=false;
                }
                Element(const std::string &_elementName,const std::string &_text)
                {
                    if(_elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    elementName=_elementName;
                    text=_text;
                    parentElement=firstChild=nextSibling=previousSibling=lastChild=nullptr;
                    alloced=false;
                }
                Element(const std::string &_elementName,const std::unordered_map<std::string,std::string> &_attribute,const std::string &_text)
                {
                    if(_elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    elementName=_elementName;
                    text=_text;
                    attribute=_attribute;
                    parentElement=firstChild=nextSibling=previousSibling=lastChild=nullptr;
                    alloced=false;
                }
                // constructors
                
                // operator overloading
                bool operator ==(const Element &_Element)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_Element.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(this->elementName==_Element.elementName&&this->attribute==_Element.attribute)
                    {
                        if(this->text==_Element.text&&this->parentElement==_Element.parentElement)
                        {
                            if(this->nextSibling==_Element.nextSibling&&this->previousSibling==_Element.previousSibling)
                            {
                                if(this->firstChild==_Element.firstChild&&this->lastChild==_Element.lastChild)
                                    return true;
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                //operator overloading
                
                //get elements
                Element& parent_element()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(parentElement==nullptr)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return *parentElement;
                }
                Element& first_child()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(firstChild==nullptr)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return *firstChild;
                }
                Element& next_sibling()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(nextSibling==nullptr)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return *nextSibling;
                }
                Element& previous_sibling()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(previousSibling==nullptr)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return *previousSibling;
                }
                Element& last_child()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(lastChild==nullptr)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return *lastChild;
                }
                // get elements
                
                //get properties
                std::string element_name()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    return elementName;
                }
                std::string class_name()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(attribute.count("class")==0)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return attribute["class"];
                }
                std::string get_attribute(const std::string &_name)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(attribute.count(_name)==0)
                    {
                        Error e("NotFoundError","The object is not found here");
                        throw e;
                    }
                    return attribute[_name]; 
                }
                // get properties 
                
                //setting properties
                void rename_element(const std::string &_elementName)
                {
                    if(_elementName=="")
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    elementName=_elementName;
                }
                void set_text(const std::string &_text)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_text=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    text=_text;
                }
                void set_attribute(const std::string &_name,const std::string &_value)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_name==""||_value=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    attribute[_name]=_value;
                }
                // setting properties
                
                //removing properties
                void remove_text()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    text="";
                }
                void remove_attribute(const std::string &_name)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_name=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    attribute.erase(_name);
                }
                //removing properties
                
                //boolean functions
                bool has_children()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    return (this->firstChild!=nullptr);
                }
                bool has_attribute(const std::string &_name)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    return (attribute.count(_name)>0);
                }
                bool has_attributes()
                {
                   if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    return (attribute.empty());
                }
                // boolean functions
                
                // modifying elements
                void append_child(Element &_Element)
                {
                    if(*this==_Element)
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_Element.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(_Element.parentElement!=nullptr)
                        _Element.parentElement->remove_child(_Element);
                    if(this->firstChild==nullptr)
                    {
                        this->firstChild=&_Element;
                        _Element.parentElement=this;
                        this->lastChild=this->firstChild;
                        return ;
                    }
                    this->lastChild->nextSibling=&_Element;
                    _Element.parentElement=this;
                    _Element.previousSibling=this->lastChild;
                    this->lastChild=this->lastChild->nextSibling;
                }
                void remove_child(Element &_Element)
                {
                    if(*this==_Element)
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(_Element.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(this->firstChild==nullptr||_Element.parentElement==nullptr||_Element.parentElement!=this)
                    {
                        Error e("InvalidElementError","The argument has incorrect ancestor for this operation");
                        throw e;
                    }
                    if(this->firstChild==&_Element)
                    {
                        if(this->firstChild==this->lastChild)
                            this->lastChild=_Element.nextSibling;
                        this->firstChild=_Element.nextSibling;
                        _Element.parentElement=_Element.nextSibling=_Element.previousSibling=nullptr;
                        return ;
                    }
                    _Element.previousSibling->nextSibling=_Element.nextSibling;
                    if(this->lastChild==&_Element)
                        this->lastChild=_Element.previousSibling;
                    _Element.parentElement=_Element.nextSibling=_Element.previousSibling=nullptr;
                }
                void replace_child(Element &_oldElement,Element &_newElement)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(*this==_oldElement||*this==_newElement)
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    if(_oldElement.elementName==""||_newElement.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(_oldElement.parentElement==nullptr||_oldElement.parentElement!=this)
                    {
                        Error e("InvalidElementError","The argument has incorrect ancestor for this operation");
                        throw e;
                    }
                    if(_newElement.parentElement!=nullptr)
                        _newElement.parentElement->remove_child(_newElement);
                    if(this->firstChild==&_oldElement)
                    {
                        if(this->firstChild==this->lastChild)
                            this->lastChild=&_newElement;
                        this->firstChild==&_newElement;
                        _newElement.parentElement=this;
                        _newElement.nextSibling=_oldElement.nextSibling;
                        _oldElement.parentElement=_oldElement.nextSibling=nullptr;
                        return ;
                    }
                    _oldElement.previousSibling->nextSibling=&_newElement;
                    if(this->lastChild==&_oldElement)
                        this->lastChild=&_newElement;
                    _newElement.parentElement=this;
                    _newElement.nextSibling=_oldElement.nextSibling;
                    _oldElement.parentElement=_oldElement.nextSibling=nullptr;
                }
                void insert_before(Element &_oldElement,Element &_newElement)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(*this==_oldElement||*this==_newElement)
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    if(_oldElement.elementName==""||_newElement.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(_oldElement.parentElement==nullptr||_oldElement.parentElement!=this)
                    {
                        Error e("InvalidElementError","The argument has incorrect ancestor for this operation");
                        throw e;
                    }
                    if(_newElement.parentElement!=nullptr)
                        _newElement.parentElement->remove_child(_newElement);
                    if(this->firstChild==&_oldElement)
                    {
                        this->firstChild=&_newElement;
                        _newElement.nextSibling=&_oldElement;
                        _newElement.parentElement=this;
                        _oldElement.previousSibling=&_newElement;
                        return ;
                    }
                    _oldElement.previousSibling->nextSibling=&_newElement;
                    _newElement.previousSibling=_oldElement.previousSibling;
                    _newElement.nextSibling=&_oldElement;
                    _oldElement.previousSibling=&_newElement;
                    _newElement.parentElement=this;
                }
                void insert_after(Element &_oldElement,Element &_newElement)
                {
                                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(*this==_oldElement||*this==_newElement)
                    {
                        Error e("InvalidModificationError","The object cannot be modified in this way");
                        throw e;
                    }
                    if(_oldElement.elementName==""||_newElement.elementName=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    if(_oldElement.parentElement==nullptr||_oldElement.parentElement!=this)
                    {
                        Error e("InvalidElementError","The argument has incorrect ancestor for this operation");
                        throw e;
                    }
                    if(_newElement.parentElement!=nullptr)
                        _newElement.parentElement->remove_child(_newElement);
                    _newElement.nextSibling=_oldElement.nextSibling;
                    if(this->lastChild!=&_oldElement)
                        _oldElement.nextSibling->previousSibling=&_newElement;
                    _oldElement.nextSibling=&_newElement;
                    _newElement.previousSibling=&_oldElement;
                    _newElement.parentElement=this;
                    return ;
                }
                void clone(Element &_Element,bool deep)
                {
                    if(this->elementName=="")
                    {
                        Error e("DataCloneError","The object cannot be cloned");
                        throw e;
                    }
                    if(_Element.elementName!="")
                    {
                        Error e("TypeMismatchError","The type of the argument does not match the expected type");
                        throw e;
                    }
                    _Element.elementName=this->elementName;
                    _Element.attribute=this->attribute;
                    _Element.text=this->text;
                    if(!deep)
                        return ;
                    std::queue<Element*> Q1;
                    Q1.push(this);
                    std::queue<Element*> Q2;
                    Q2.push(&(_Element));
                    bool first=true;
                    while(!Q1.empty())
                    {
                        Element **r;
                        Element *par;
                        Element *q=nullptr;
                        if(first)
                        {
                            par=&_Element;
                            r=&(par->firstChild);
                            first=false;
                        }
                        else
                        {
                            par=Q2.front();
                            r=&(par->firstChild);
                        }
                        Q2.pop();
                        Element *p=Q1.front();
                        Q1.pop();
                        p=p->firstChild;
                        while(p!=nullptr)
                        {
                            Element *temp=new Element(p->elementName,p->attribute,p->text);
                            (*r)=temp;
                            par->lastChild=temp;
                            temp->parentElement=par;
                            temp->previousSibling=q;
                            temp->alloced=true;
                            Q1.push(p);
                            Q2.push(temp);
                            p=p->nextSibling;
                            r=&((*r)->nextSibling);
                            q=temp;
                        }
                        _Element.alloced=true;
                    }
                }
                // modifying elements
                
                //displaying
                std::string to_html()
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    std::string temp_string="";
                    this->dfs(temp_string);
                    return temp_string;
                }
                void dump(std::string filename)
                {
                    if(this->elementName=="")
                    {
                        Error e("InvalidStateError","The object is in an invalid state");
                        throw e;
                    }
                    if(filename=="")
                    {
                        Error e("InvalidArgumentError","The argument is in an invalid state");
                        throw e;
                    }
                    std::string data=this->to_html();
                    std::ofstream fout;
                    std::string loc=filename+".html";
                    fout.open(loc);
                    fout<<data;
                    fout.close();
                }
                //displaying
                
                //destructor
                ~Element()
                {
                    if(alloced)
                    {   
                        std::vector<Element*> temp;
                        std::queue<Element*> Q;
                        Q.push(this);
                        while(!Q.empty())
                        {
                            Element *p=Q.front();
                            Q.pop();
                            p=p->firstChild;
                            while(p!=nullptr)
                            {
                                if(p->alloced)
                                {
                                    Q.push(p);
                                    temp.push_back(p);
                                }
                                p=p->nextSibling;
                            }
                        }
                        for(int i=0;i<temp.size();i++)
                        {
                            Element *del=temp[i];
                            temp[i]=nullptr;
                            delete del;
                        }
                    }
                }
                //destructor
    private:std::string elementName;
                Element *parentElement;
                Element *firstChild;
                Element *nextSibling;
                Element *previousSibling;
                Element *lastChild;
                bool alloced;
                std::string text;
                std::unordered_map<std::string,std::string> attribute;
                void dfs(std::string &html_string)
                {
                    html_string=html_string+"<"+this->elementName;
                    if(!this->attribute.empty())
                    {
                        for(auto &x:this->attribute)
                            html_string=html_string+" "+x.first+"=\""+x.second+"\"";
                    }
                    html_string=html_string+">\n";
                    if(!this->text.empty())
                        html_string=html_string+this->text+"\n";
                    Element *p=this->firstChild;
                    while(p!=nullptr)
                    {
                        p->dfs(html_string);
                        p=p->nextSibling;
                    }
                    html_string=html_string+"</"+this->elementName+">\n";
                }
    };
};
#endif