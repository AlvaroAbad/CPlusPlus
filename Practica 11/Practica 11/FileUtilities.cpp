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
		void getnumbers(Archivo * file, TList * list)
		{
			void * buffer;
			unsigned int charsToRead;
			unsigned int CharsRead = 0;
			bool remainingFileToread = true;
			fseek(file->file, 0, SEEK_END);
			long fileSize = ftell(file->file);
			rewind(file->file);
			if (fileSize < 128) {
				buffer = malloc(sizeof(char) * (fileSize + 1));
				charsToRead = fileSize;
			}
			else {
				buffer = malloc(sizeof(char) * (128 + 1));
				charsToRead = 128;
			}
			char * match = static_cast<char *>(buffer);
			char * lastmatch = static_cast<char *>(buffer);
			do {
				CharsRead = readFile(match, charsToRead, file);
				match = static_cast<char *>(buffer);
				lastmatch = static_cast<char *>(buffer);
				while ((match = strstr((match), ",")) != 0) {
					strncpy(match, "\0", 1);
					list->push(lastmatch);
					lastmatch = match + 1;
					match = match + 1;
				}
				if (CharsRead == charsToRead) {
					unsigned int i = 0;
					while (lastmatch[i]) {
						static_cast<char *>(buffer)[i] = lastmatch[i];
						i++;
					}
					match = static_cast<char *>(buffer) + i;
					lastmatch = static_cast<char *>(buffer) + i;
					charsToRead = 128 - i;
				}
				else {
					remainingFileToread = false;
				}
			} while (remainingFileToread);
			list->push(lastmatch);
			free(buffer);
		}
	}
}
