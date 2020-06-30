
import java.util.*;

public class JavaDictionary {

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

		private String keyword, speech, def;

		data(String keyword, String speech, String def) {
			this.setKeyword(keyword);
			this.setSpeech(speech);
			this.setDef(def);
		}

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

		public String toString() {
			return this.keyword + " [" + this.speech + "] : " + def;
		}

	}

	public static void main(String[] args) {

		System.out.println("! Loading data...");

		List<String> keywordList = new ArrayList<>();
		List<String> speechList = new ArrayList<>();
		List<String> defList = new ArrayList<>();

		for (data entry : data.values()) {
			keywordList.add(entry.keyword);
			speechList.add(entry.speech);
			defList.add(entry.def);
		}

		System.out.println("! Loading completed...\n\n" + "-----DICTIONARY 340 JAVA-----\n");

		Scanner sc = new Scanner(System.in);

		boolean inProgress = true;

		while (inProgress) {
			

			System.out.print("Search: ");
			String[] input = sc.nextLine().toLowerCase().split(" ");
			Iterator<String> keywordIterator = keywordList.iterator();
			Iterator<String> speechIterator = speechList.iterator();
			Iterator<String> defIterator = defList.iterator();
			boolean found = false;
			String dPrev = "";
			String sPrev = "";
			switch (input.length) {

			case 1:
				
				if (input[0].equals("!q")) {
					System.out.println("\n-----THANK YOU-----");
					inProgress = false;
					break;
				}
				System.out.println("    |");
				while (keywordIterator.hasNext()) {
					String k = keywordIterator.next();
					String s = speechIterator.next();
					String d = defIterator.next();
					if(input[0].equals(k.toLowerCase())) {
						System.out.println("     " + k + " [" + s + "] : " + d);
						found = true;
					}
				}
				if(!found) {
					System.out.println("     <Not found>");
				}
				System.out.println("    |");
				break;
			
			case 2:
				System.out.println("    |");
				if(!input[1].equals("distinct") && !speechList.contains(input[1])) {
					System.out.println("     <2nd argument must be a part of speech or \"distinct\">");
					found = true;
				}
				while (keywordIterator.hasNext()) {
					String k = keywordIterator.next();
					String s = speechIterator.next();
					String d = defIterator.next();
					if(input[0].equals(k.toLowerCase())) {
						if(input[1].equals(s)) {
							System.out.println("     " + k + " [" + s + "] : " + d);
							found = true;
						} else if(input[1].equals("distinct")) {
							if(!d.equals(dPrev) || !s.equals(sPrev)) {
								System.out.println("     " + k + " [" + s + "] : " + d);
								found = true;
							}
						}
					}
					dPrev = d;
					sPrev = s;
				}
				if(!found) {
					System.out.println("     <Not found>");
				}
				System.out.println("    |");
				break;
				
			case 3:
				System.out.println("    |");
				if(!speechList.contains(input[1])) {
					System.out.println("     <2nd argument must be a part of speech or \"distinct\">");
					found = true;
				}
				if(!input[2].equals("distinct")) {
					System.out.println("     <3rd argument must be \"distinct\">");
					found = true;
				}
				while (keywordIterator.hasNext()) {
					String k = keywordIterator.next();
					String s = speechIterator.next();
					String d = defIterator.next();
					if(input[0].equals(k.toLowerCase())) {
						if(input[1].equals(s) && (!d.equals(dPrev) || !s.equals(sPrev))) {
							System.out.println("     " + k + " [" + s + "] : " + d);
							found = true;
						}
					}
					dPrev = d;
					sPrev = s;
				}
				if(!found) {
					System.out.println("     <Not found>");
				}
				System.out.println("    |");
				break;
			}

		}
	}
}