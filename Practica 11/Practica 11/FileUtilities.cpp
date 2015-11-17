#include "FileFunctions.h"
#include "FileUtilities.h"
namespace fileOperators {
	namespace fileUtilities {
		unsigned int countCoincidence(Archivo * file, const char * string) {
			if (string) {
				unsigned int matches = 0;
				fseek(file->file, 0, SEEK_END);
				long fileSize = ftell(file->file);// get file size to create buffer
				rewind(file->file);
				void * buffer = malloc(sizeof(char) * (fileSize + 1));
				readFile(buffer, static_cast<unsigned int>(fileSize), file);
				char * match = static_cast<char *>(buffer);
				while ((match = strstr(match + 1, string)) != 0) {
					matches++;
				}
				free(buffer);
				return matches;
			}
			else {
				return 0;
			}
		}

		int addNumbers(Archivo * file) {
			int total = 0;
			int i = -1;
			fseek(file->file, 0, SEEK_END);
			long fileSize = ftell(file->file);
			rewind(file->file);
			void * buffer = malloc(sizeof(char) * (fileSize + 1));
			readFile(buffer, static_cast<unsigned int>(fileSize), file);
			char * match = static_cast<char *>(buffer);
			char * lastmatch = match;
			while ((match = strstr((match + 1), ",")) != 0) {
				strncpy_s(match, 1, "\0", 1);
				while (match[i] != '\0' && (match + i) > static_cast<char *>(buffer)) {
					i--;
				}
				if ((match + i) == static_cast<char *>(buffer)) {
					total += atoi(match + i);
				}
				else {
					total += atoi(match + (i + 1));
				}
				i = -1;
				lastmatch = match;
			}
			total += atoi(lastmatch + 1);
			free(buffer);
			return total;
		}
		TList * getnumbers(Archivo * file)
		{
			TList * list = new TList();
			fseek(file->file, 0, SEEK_END);
			long fileSize = ftell(file->file);
			rewind(file->file);
			void * buffer = malloc(sizeof(char) * (fileSize + 1));
			int i = -1;
			readFile(buffer, static_cast<unsigned int>(fileSize), file);
			char * match = static_cast<char *>(buffer) - 1;
			while ((match = strstr((match + 1), ",")) != 0) {
				strncpy(match, "\0", 1);
				while (match[i] != '\0' && (match + i) > static_cast<char *>(buffer)) {
					i--;
				}
				if ((match + i) == static_cast<char *>(buffer)) {
					list->push(match + i);
				}
				else {
					list->push(match + (i + 1));
				}

				i = -1;
			}
			free(buffer);
			return list;
		}
	}
}
