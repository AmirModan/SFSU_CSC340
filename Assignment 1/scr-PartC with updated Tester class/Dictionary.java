// package info here if needed

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Amir Modan:
 * 
 *This program includes a tester intended for the sample output in Part B.
 *If you are looking for the original tester, look in the folder "src-PartC".
 *
 */
public class Dictionary {

	// Feel Free to add more methods

	/**
	 *
	 * Consider starting Here
	 *
	 */
	//Data Structures that will contain the dictionary data
	static List<String> keywordList = new ArrayList<>();
	static List<String> speechList = new ArrayList<>();
	static List<String> defList = new ArrayList<>();
	
	//Enum objects that contain the dictionary data initially
	public enum data {

		ARROW_NOUN_1("arrow", "noun", "Here is one arrow: <IMG> -=>> </IMG>"),

		DISTINCT_ADJECTIVE_1("Distinct", "adjective", "Familiar. Worked with Java."),
		DISTINCT_ADJECTIVE_2("Distinct", "adjective",
				"Unique. No duplicates. Clearly different or of a different kind."),
		DISTINCT_ADVERB_1("Distinct", "adverb", "Uniquely. Written \"distinctly\"."),
		DISTINCT_NOUN_1("Distinct", "noun", "A Keyword in this assignment"),
		DISTINCT_NOUN_2("Distinct", "noun", "A Keyword in this assignment"),
		DISTINCT_NOUN_3("Distinct", "noun", "A Keyword in this assignment"),
		DISTINCT_NOUN_4("Distinct", "noun", "An advanced search option"),
		DISTINCT_NOUN_5("Distinct", "noun", "Distinct is a parameter in this assignment"),

		PLACEHOLDER_ADJECTIVE_1("Placeholder", "adjective", "To be updated. . ."),
		PLACEHOLDER_ADJECTIVE_2("Placeholder", "adjective", "To be updated. . ."),
		PLACEHOLDER_ADVERB_1("Placeholder", "adverb", "To be updated. . ."),
		PLACEHOLDER_CONJUNCTION_1("Placeholder", "conjunction", "To be updated. . ."),
		PLACEHOLDER_INTERJECTION_1("Placeholder", "interjection", "To be updated. . ."),
		PLACEHOLDER_NOUN_1("Placeholder", "noun", "To be updated. . ."),
		PLACEHOLDER_NOUN_2("Placeholder", "noun", "To be updated. . ."),
		PLACEHOLDER_NOUN_3("Placeholder", "noun", "To be updated. . ."),
		PLACEHOLDER_PREPOSITION_1("Placeholder", "preposition", "To be updated. . ."),
		PLACEHOLDER_PRONOUN_1("Placeholder", "pronoun", "To be updated. . ."),
		PLACEHOLDER_VERB_1("Placeholder", "verb", "To be updated. . ."),

		CSC220_ADJECTIVE_1("CSC220", "adjective", "Ready to create complex data structures."),
		CSC220_VERB_1("CSC220", "verb", "To create data structures."),

		CSC340_ADJECTIVE_1("CSC340", "adjective", "= C++ version of CSC210 + CSC220 + more."),
		CSC340_NOUN_1("CSC340", "noun", "A CS upper division course."),
		CSC340_NOUN_2("CSC340", "noun", "Many hours outside of class."),
		CSC340_NOUN_3("CSC340", "noun", "Programming Methodology."),

		BOOK_NOUN_1("Book", "noun", "A set of pages."),
		BOOK_NOUN_2("Book", "noun", "A written work published in printed or electronic form."),
		BOOK_VERB_1("Book", "verb", "To arrange for someone to have a seat on a plane."),
		BOOK_VERB_2("Book", "verb", "To arrange something on a particular date."),

		ADVERB_NOUN_1("Adverb", "noun",
				"Adverb is a word that adds more information about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb."),

		ADJECTIVE_NOUN_1("Adjective", "noun",
				"Adjective is a word that describes a person or thing, for example big, red and clever in a big house, red wine and a clever idea."),

		INTERJECTION_NOUN_1("Interjection", "noun",
				"Interjection is a short sound, word or phrase spoken suddenly to express an emotion. Oh!, Look out! and Ow! are interjections."),

		NOUN_NOUN_1("Noun", "noun",
				"Noun is a word that refers to a person, (such as Ann or doctor), a place (such as Paris or city) or a thing, a quality or an activity (such as plant, sorrow or tennis.");
		//data fields for enum object
		private String keyword, speech, def;

		//default constructor for enum object
		data() {
			this.setKeyword("");
			this.setSpeech("");
			this.setDef("");
		}

		//constructor for enum object
		data(String keyword, String speech, String def) {
			this.setKeyword(keyword);
			this.setSpeech(speech);
			this.setDef(def);
		}

		//setter and getter methods for enum object
		public String getKeyword() {
			return keyword;
		}

		public void setKeyword(String keyword) {
			this.keyword = keyword;
		}

		public String getSpeech() {
			return speech;
		}

		public void setSpeech(String speech) {
			this.speech = speech;
		}

		public String getDef() {
			return def;
		}

		public void setDef(String def) {
			this.def = def;
		}

		//toString method for enum object
		public String toString() {
			return this.keyword + " [" + this.speech + "] : " + def;
		}

	}
	//init method which will load the data from enum objects to data structures
	public static void init() {
		System.out.println("! Loading data...");
		for (data entry : data.values()) {
			keywordList.add(entry.keyword);
			speechList.add(entry.speech);
			defList.add(entry.def);
		}
		System.out.println("! Loading completed...\n\n" + "-----DICTIONARY 340 JAVA-----\n");
	}

	/**
	 * Process dictionary querry data and returns meaningful data
	 *
	 * @param word       the word to be processed or null
	 * @param speechType The SpeechType to check or null
	 * @param distinct   boolean whether or not to remove duplicates
	 * @return an ArrayList of Strings where each entry is properly formatted for
	 *         output EX: for a word named "word" ["word [PartOfSpeech1]
	 *         Definition1", "word [PartOfSpeech2] Definition2"] for a word not in
	 *         the Dictionary_Template ["none"]
	 *
	 *
	 */
	public static ArrayList<String> querryDictionary(String word, String speechType, boolean distinct) {

		// add implementation here
		ArrayList<String> list = new ArrayList<>();
		if (word == null) {
			list.add("<Not found in dictionary>");
			return list;
		} else if(speechType != null && !speechList.contains(speechType)) {
			list.add("<Second argument must be part of speech or \'distinct\'>");
			return list;
		}
		boolean found = false;
		if (word.equals("!q")) {
			list.add("\n-----THANK YOU-----");
			found = true;
		}

		Iterator<String> keywordIterator = keywordList.iterator();
		Iterator<String> speechIterator = speechList.iterator();
		Iterator<String> defIterator = defList.iterator();
		String dPrev = "";
		String sPrev = "";

		if (speechType == null && !distinct) {
			while (keywordIterator.hasNext()) {
				String k = keywordIterator.next();
				String s = speechIterator.next();
				String d = defIterator.next();
				if (word.toLowerCase().equals(k.toLowerCase())) {
					list.add(k + " [" + s + "] : " + d);
					found = true;
				}
			}
		} else if (!distinct) {
			
			while (keywordIterator.hasNext()) {
				String k = keywordIterator.next();
				String s = speechIterator.next();
				String d = defIterator.next();
				if (word.toLowerCase().equals(k.toLowerCase())) {
					if (speechType.equals(s)) {
						list.add(k + " [" + s + "] : " + d);
						found = true;
					} else if (speechType.equals("distinct")) {
						if (!d.equals(dPrev) || !s.equals(sPrev)) {
							list.add(k + " [" + s + "] : " + d);
							found = true;
						}
					}
				}
				dPrev = d;
				sPrev = s;
			}
		} else if(speechType == null) {
			
			while (keywordIterator.hasNext()) {
				String k = keywordIterator.next();
				String s = speechIterator.next();
				String d = defIterator.next();
				if (word.toLowerCase().equals(k.toLowerCase())) {
					if (!distinct) {
						list.add(k + " [" + s + "] : " + d);
						found = true;
					} else if (distinct && (!d.equals(dPrev) || !s.equals(sPrev))) {
						list.add(k + " [" + s + "] : " + d);
						found = true;
					}
				}
				dPrev = d;
				sPrev = s;
			}
			
		} else {

			while (keywordIterator.hasNext()) {
				String k = keywordIterator.next();
				String s = speechIterator.next();
				String d = defIterator.next();
				if (word.toLowerCase().equals(k.toLowerCase())) {
					if (!distinct) {
						list.add(k + " [" + s + "] : " + d);
						found = true;
					} else if (distinct && speechType.equals(s) && (!d.equals(dPrev) || !s.equals(sPrev))) {
						list.add(k + " [" + s + "] : " + d);
						found = true;
					}
				}
				dPrev = d;
				sPrev = s;
			}
		}

		if (!found) {
			list.add("<Not found in dictionary>");
		}
		return list; // make sure to return the correct data
	}

}
