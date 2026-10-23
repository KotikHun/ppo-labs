#pragma once
#include "Document.h"
#include "Id.h"

/** @brief Contract document. */
class Contract : public Document {
private:
    Id guestId;
public:
    Contract();
    Contract(const std::string& documentNumber, const Date& issueDate, const Date& expiryDate, const Id& guestId);
    Contract(const Contract& other);
    Contract& operator=(const Contract& other);
    virtual ~Contract();

    Id getGuestId() const;
    void setGuestId(const Id& guestId);

    bool isValid(const Date& currentDate) const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Contract& c);
};