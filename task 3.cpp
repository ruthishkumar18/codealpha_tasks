#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Sentiment analysis function (basic, based on keywords)
string analyzeSentiment(const string& sentence) {
    string lowerSentence = sentence;
    transform(lowerSentence.begin(), lowerSentence.end(), lowerSentence.begin(), ::tolower);
    
    if (lowerSentence.find("happy") != string::npos || lowerSentence.find("good") != string::npos) {
        return "Positive";
    }
    else if (lowerSentence.find("sad") != string::npos || lowerSentence.find("angry") != string::npos) {
        return "Negative";
    }
    else {
        return "Neutral";
    }
}

// Dialogue management function
string getResponse(const string& input) {
    map<string, string> responses;
    responses["hello"] = "Hi there! How can I assist you today?";
    responses["how are you"] = "I'm just a bot, but I'm doing great! How about you?";
    responses["what is your name"] = "I am a simple AI chatbot.";
    responses["bye"] = "Goodbye! Have a nice day!";
    responses["what is the weather today"] = "Sorry, I can't fetch real-time weather data right now.";
    responses["tell me a joke"] = "Why don't scientists trust atoms? Because they make up everything!";
    
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    // Search for response
    if (responses.find(lowerInput) != responses.end()) {
        return responses[lowerInput];
    } else {
        return "Sorry, I don't understand that. Could you please rephrase?";
    }
}

int main() {
    string input;
    cout << "Hello! I'm your AI Chatbot. Type 'bye' to exit.\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, input);

        if (input == "bye") {
            cout << "Chatbot: Goodbye! Have a nice day!" << endl;
            break;
        }

        // Analyze sentiment
        string sentiment = analyzeSentiment(input);
        cout << "Sentiment Analysis: " << sentiment << endl;

        // Get response based on the input
        string response = getResponse(input);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
