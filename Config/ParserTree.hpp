#ifndef PARSER_TREE
#define PARSER_TREE

#include <list>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

class Parser_Tree
{
	public:
		typedef Parser_Tree* Node_Ptr;

		Parser_Tree() { };
		virtual ~Parser_Tree()
		{
			if(!_children.empty()) {
				for(std::list< Node_Ptr >::iterator it = _children.begin(); it != _children.end(); it++) {
					delete *it;
				}
			}
		}

		void addChild(const Node_Ptr child)
		{
			_children.push_back(child);
		}

		Node_Ptr getChild(const std::string header)
		{
			if(!_children.empty()) {
				for(std::list< Node_Ptr >::iterator it = _children.begin(); it != _children.end(); it++) {
					if((*it)->_header == header) {
						return *it;
					}
				}
			}
			return NULL;
		}

		Node_Ptr getNextChild()
		{
			if(_parent != NULL) {
				std::list< Node_Ptr >::iterator it = std::find(_parent->_children.begin(), _parent->_children.end(), this);

				if(it != _parent->_children.end()) {
					for(it++; it != _parent->_children.end(); it++) {
						if((*it)->_header == this->_header) {
							return *it;
						}
					}
				}
			}
			return NULL;
		}

		void setData(const std::string data)
		{
			_data = data;
		}

		const std::string getData()
		{
			return _data;
		}

		const std::string getAttribut(const std::string type)
		{
			std::map< std::string, std::string >::iterator it = _attributs.find(type);
			if(it != _attributs.end()) {
				return it->second;
			}

			return "";
		}

		void addAttribut(const std::pair< std::string, std::string > attribut)
		{
			_attributs.insert(attribut);
		}

	protected:
		std::string _header;
		std::string _data;

		std::map< std::string, std::string > _attributs;

		Node_Ptr _parent;
		std::list< Node_Ptr > _children;
};

#endif
