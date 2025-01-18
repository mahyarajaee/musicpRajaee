#include <iostream>
#include <string>
using namespace std;

struct Song {
	string title;
	string artist;
	string genre;
	double duration;
	Song *link;
	Song* prev;
};

class Playlist {
private:
	Song* first;
	Song* last;
public:
	Playlist() :first(nullptr), last(nullptr) {}
	 
	// اضافه کردن آهنگ به آخر لیست
	void addSong(const string& title, const string& artist, const string& genre, double duration)
	{
		Song* newSong = new Song{ title,artist,genre,duration,nullptr,nullptr};
		if (!first) {
			first =last= newSong;
		}
		else {
			last->link = newSong;
			newSong->prev = last;
			last = newSong;
		}
		cout << "Song Added:" << title << endl;

	}
	 
	//حذف اهنگ با اسم
	void removeSongByTitle(const string& title) 
	{
		if (!first) {
			cout << "playlist in empty" << endl;
			return;
		}
		Song* current = first;
		while (current) 
		{
			if (current->title == title) {
				if (current == first) {
					first = first->link;
					if (first)first->prev = nullptr;
				}
				else if (current == last) {
					last = last->prev;
					if (last)last->link = nullptr;
				}
				else {
					current->prev->link = current->link;
					current->link->prev = current->prev;
				}
				delete current;
				cout << "song removed: " << title << endl;
				return;
			}
			current = current->link;
		}
		cout << "song noy found;" << endl;
	}

	void removeSongByArtist(const string& artist) 
	{
		if (!first) {
			cout << "playlist is empty" << endl;
			return;
		}
		Song* current = first;
		while (current) {
			if (current->artist == artist) {
				if (current == first) {
					first = first->link;
					if (first)first->prev = nullptr;
						
				}
				else if (current == last) {
					last = last->prev;
						if(last)last->link = nullptr;
				}
				else {
					current->prev->link = current->link;
					current->link->prev = current->prev;
				}
				delete current;
			}
			else {
				current = current->link;
			}
		}
		cout << "songs by " << artist << " removed" << endl;
	}

	void removeSongByGenre(const string& genre) {
		if (!first) {
			cout << "playlist is empty" << endl;
			return;
		}
		Song* current = first;
		while (current) {
			if (current->genre == genre) {
				if (current == first) {
					first = first->link;
					if (first)first->prev = nullptr;

				}
				else if (current == last) {
					last = last->prev;
					if (last)last->link = nullptr;
				}
				else {
					current->prev->link = current->link;
					current->link->prev = current->prev;
				}
				delete current;
			}
			else {
				current = current->link;
			}
		}
		cout << "songs with genre " << genre << " removed" << endl;

	}

	void searchSongByTitle(const string& title)
	{
		Song* current = first;
		while (current) 
		{
			if (current->title == title) {
				cout << "found: " << current->title << "by" << current->artist << endl;
				return;
			}

			current = current->link;
		}

		cout << "song not found:)" << endl;
	
	}

	void displayPlaylist()
	{
		if (!first) {
			cout << "playlist is empty" << endl;
			return;
		}
		Song* current = first;
		while (current) {
			cout << current->title << "by" << current->artist << "," << current->genre << "," << current->duration << "mins" << endl;
			current = current->link;
		}
	}


	void sortPlaylist() {
		if (!first || !first->link)return;
		for (Song* i = first; i->link; i = i->link) {
			for (Song* j = i->link; j; j = j->link) {
				if (i->title > j->title) {
					string tempTitle = i->title;
					i->title = j->title;
					j->title = tempTitle;

					string tempArtist = i->artist;
					i->artist = j->artist;
					j->artist = tempArtist;

					string tempGenre = i->genre;
					i->genre = j->genre;
					j->genre = tempGenre;

					double tempduration = i->duration;
					i->duration = j->duration;
					j-> duration= tempduration;
				}
			}
		}
		cout << "playlist sorted" << endl;
	}
};






int main()
{
	Playlist playlist;
	 
	playlist.addSong(" kenaretam", "Ali Yasini", "Pop", 3.32);
	playlist.addSong(" Asabani", "shayea", "Rap", 4.49);
	playlist.addSong(" Ay setareh", "Hamim", "Pop", 2.35);
	playlist.addSong(" Az Ghasd", "Hamim", "Pop", 3.04);



	cout << "Playlist:" << endl;
	playlist.displayPlaylist();

	playlist.searchSongByTitle("Asabani");

	playlist.removeSongByTitle("kenaretam");

	playlist.sortPlaylist();
	cout << "sorted playlist: " << endl;
	playlist.displayPlaylist();

	return 0;
}

