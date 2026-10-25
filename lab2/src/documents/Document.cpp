#include "Document.h"
#include <sstream>

using namespace std;

Document::Document() : documentNumber(""), issueDate(), expiryDate() {}

Document::Document(const string& documentNumber, const Date& issueDate, const Date& expiryDate)
    : documentNumber(documentNumber), issueDate(issueDate), expiryDate(expiryDate) {}

Document::Document(const Document& other)
    : id(other.id), documentNumber(other.documentNumber),
      issueDate(other.issueDate), expiryDate(other.expiryDate) {}

Document& Document::operator=(const Document& other) {
    if (this == &other) return *this;
    id = other.id;
    documentNumber = other.documentNumber;
    issueDate = other.issueDate;
    expiryDate = other.expiryDate;
    return *this;
}

Document::~Document() {}

Id Document::getId() const { return id; }
string Document::getDocumentNumber() const { return documentNumber; }
Date Document::getIssueDate() const { return issueDate; }
Date Document::getExpiryDate() const { return expiryDate; }

void Document::setDocumentNumber(const string& documentNumber) { this->documentNumber = documentNumber; }
void Document::setIssueDate(const Date& issueDate) { this->issueDate = issueDate; }
void Document::setExpiryDate(const Date& expiryDate) { this->expiryDate = expiryDate; }

string Document::toString() const {
    stringstream ss;
    ss << "Document{id=" << id.toString() << ", number=" << documentNumber
       << ", expires=" << expiryDate.toString() << "}";
    return ss.str();
}

bool Document::operator==(const Document& other) const { return id == other.id; }
bool Document::operator!=(const Document& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Document& d) {
    os << d.toString();
    return os;
}