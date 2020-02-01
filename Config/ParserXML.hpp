#ifndef PARSER_XML
#define PARSER_XML

#include <string>

#include "ParserTree.hpp"

namespace Parser
{
	class Parser_XML : public Parser_Tree
	{
		public:
			Parser_XML();
			virtual ~Parser_XML();

			/* Read the XML file and parse it into a tree */
			void load_file(const std::string file);
		private:
			/* Reading the first and second next tokens */
			const char read_current_token(const std::string& chaine);
			const char read_next_token(const std::string& chaine);

			/* Read and destroy the next token */
			void destroy_current_token(std::string& chaine, const char token);

			/* Manage the suppression of bad (tab or /n) characters */
			void erase_all_characters(std::string& str, char character);

			/* Function which recognize a word */
			const std::string word_grammar(std::string& chaine);
			void word_list(std::string& chaine, std::string& mot);

			/* Function which recognize a float */
			std::string number_grammar(std::string& chaine);
			std::string number(std::string& chaine);
			void number_list(std::string& chaine, std::string& nombre);
			void number_float(std::string& chaine, std::string& nombre);
			void number_float_list(std::string& chaine, std::string& nombre);

			/* Function which recognize a string with spaces characters */
			std::string string(std::string& chaine);
			void string_list(std::string& chaine, std::string& str);

			/* Manage the header of an XML tag */
			const std::string header(std::string& chaine, const std::string& header_prec);

			/* Manage the properties of an XML tag */
			const std::string type(std::string& chaine);
			const std::string attribut(std::string& chaine);
			void attribut_list(std::string& chaine);

			/* Manage the data of an XML tag (string or sub tags) */
			void data(std::string& chaine);

			/* Manage the grammar of an XML tag */
			void tag(std::string& chaine);

		private:
			std::string file_content;
	};
};

#endif
