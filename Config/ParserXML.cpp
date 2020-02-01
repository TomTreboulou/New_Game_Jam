#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "ParserTree.hpp"
#include "ParserXML.hpp"

#define ASCII_WORD(X)	((((X) >= 'a' && (X) <= 'z') || ((X) >= 'A' && (X) <= 'Z') || ((X) >= '0' && (X) <= '9'))  ? (true) : (false))
#define ASCII_NUM(X)	(((X) >= '0' && (X) <= '9') ? (true) : (false))

namespace Parser
{
	Parser_XML::Parser_XML()
	{

	}

	Parser_XML::~Parser_XML()
	{

	}

	void Parser_XML::load_file(const std::string file)
	{
		std::ifstream xml_file(file.c_str());

		if(xml_file) {
			file_content.assign((std::istreambuf_iterator<char>(xml_file)),
				     	     std::istreambuf_iterator<char>());

			xml_file.close();

			erase_all_characters(file_content, '\n');
			erase_all_characters(file_content, '\t');

			this->tag(file_content);
		}

	}

	void Parser_XML::erase_all_characters(std::string& str, char character)
	{
		str.erase(std::remove(str.begin(), str.end(), character), str.end());
	}

	const char Parser_XML::read_current_token(const std::string& chaine)
	{
		return chaine[0];
	}

	const char Parser_XML::read_next_token(const std::string& chaine)
	{
		return chaine[1];
	}

	void Parser_XML::destroy_current_token(std::string& chaine, const char token)
	{
		if(read_current_token(chaine) == token) {
			chaine.erase(chaine.begin(), chaine.begin() + 1);
		}
	}

	const std::string Parser_XML::word_grammar(std::string& chaine)
	{
		std::string word;
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			destroy_current_token(chaine, current_token);
			word.push_back(current_token);

			word_list(chaine, word);
		}

		return word;
	}

	void Parser_XML::word_list(std::string& chaine, std::string& word)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			destroy_current_token(chaine, current_token);
			word.push_back(current_token);

			word_list(chaine, word);
		}
	}

	/* Function which recognize a float */
	std::string Parser_XML::number_grammar(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);
		std::string number;

		if(ASCII_NUM(current_token)) {
			std::string number_str = this->number(chaine);
		}
		return number;
	}


	std::string Parser_XML::number(std::string& chaine)
	{
		std::string number;
		const char current_token = read_current_token(chaine);

		if(ASCII_NUM(current_token)) {
			destroy_current_token(chaine, current_token);
			number.push_back(current_token);

			number_list(chaine, number);
		}
		return number;
	}


	void Parser_XML::number_list(std::string& chaine, std::string& number)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_NUM(current_token)) {
			destroy_current_token(chaine, current_token);
			number.push_back(current_token);

			number_list(chaine, number);
		} else if(current_token == '<') {
		} else if(current_token == '.') {
			destroy_current_token(chaine, current_token);
			number.push_back(current_token);

			number_float(chaine, number);
		}
	}


	void Parser_XML::number_float(std::string& chaine, std::string& number)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_NUM(current_token)) {
			destroy_current_token(chaine, current_token);
			number.push_back(current_token);

			number_float_list(chaine, number);
		}
	}


	void Parser_XML::number_float_list(std::string& chaine, std::string& number)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_NUM(current_token)) {
			destroy_current_token(chaine, current_token);
			number.push_back(current_token);

			number_float_list(chaine, number);
		}
	}


	/* Function which recognize a string with spaces characters */
	std::string Parser_XML::string(std::string& chaine)
	{
		std::string str;
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			std::string current_word = word_grammar(chaine);
			str += current_word;

			string_list(chaine, str);
		}

		return str;
	}

	void Parser_XML::string_list(std::string& chaine, std::string& str)
	{
		const char current_token = read_current_token(chaine);

		if(current_token == ' ') {
			destroy_current_token(chaine, current_token);
			str.push_back(current_token);
			std::string current_word = word_grammar(chaine);
			str += current_word;

			string_list(chaine, str);
		}
	}

	/* Manage the header of an XML tag */
	const std::string Parser_XML::header(std::string& chaine, const std::string& header_prec)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			const std::string header = word_grammar(chaine);
			return header;
		}
		return "";
	}


	/* Manage the properties of an XML tag */
	const std::string Parser_XML::type(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			return word_grammar(chaine);
		}

		return "";
	}

	const std::string Parser_XML::attribut(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);

		if(ASCII_WORD(current_token)) {
			return word_grammar(chaine);
		}

		return "";
	}


	void Parser_XML::attribut_list(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);

		if(current_token == ' ') {
			std::string str_type, str_attribut;

			destroy_current_token(chaine, current_token);
			str_type = type(chaine);
			destroy_current_token(chaine, '=');
			destroy_current_token(chaine, '\"');
			str_attribut = attribut(chaine);
			destroy_current_token(chaine, '\"');

			this->addAttribut(std::pair< std::string, std::string >(str_type, str_attribut));

			attribut_list(chaine);
		}
	}

	/* Manage the data of an XML tag (string or sub tags) */
	void Parser_XML::data(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);
		const char next_token = read_next_token(chaine);

		if(ASCII_WORD(current_token)) {
			std::string data = string(chaine);
			this->setData(data);
		} else if(ASCII_NUM(current_token)) {
			std::string data = number_grammar(chaine);
			this->setData(data);
		} else if(current_token == '<' && ASCII_WORD(next_token)) {
			this->setData("");

			Parser_XML* current_child = new Parser_XML;

			if(current_child != NULL) {
				current_child->tag(chaine);

				this->addChild(current_child);
				current_child->_parent = this;
			}

			data(chaine);
		}
	}

	/* Manage the grammar of an XML tag */
	void Parser_XML::tag(std::string& chaine)
	{
		const char current_token = read_current_token(chaine);

		if(current_token == '<') {
			destroy_current_token(chaine, current_token);
			const std::string header = this->header(chaine, "");

			_header = header;

			attribut_list(chaine);
			destroy_current_token(chaine, '>');

			data(chaine);

			destroy_current_token(chaine, '<');
			destroy_current_token(chaine, '/');
			this->header(chaine, header);
			destroy_current_token(chaine, '>');
		}
	}
};
