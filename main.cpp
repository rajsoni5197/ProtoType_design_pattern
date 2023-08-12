#include <iostream>
using namespace std;

class Document
{
protected:
    string documentName;
    unsigned int documentId;

public:
    Document(){};

    virtual Document *clone() = 0;
    string getDocumentName() const
    {
        return documentName;
    }

    unsigned int getDocumentId() const
    {
        return documentId;
    }

    // Setters
    void setDocumentName(const string &name)
    {
        documentName = name;
    }

    void setDocumentId(unsigned int id)
    {
        documentId = id;
    }
    virtual void printAttributes() const {
        std::cout << "Document ID: " << documentId << std::endl;
        std::cout << "Document Name: " << documentName << std::endl;
    }
};
class Invoice : public Document
{
protected:
    int invoiceId;
    string invoiceName;
    string issueDate;
    string dueDate;
    string sellerName;
    unsigned int sellerGstNo;
    string buyerName;
    unsigned int sumTotal;

public:
    Invoice(){

    };
    int getInvoiceId() const
    {
        return invoiceId;
    }

    string getInvoiceName() const
    {
        return invoiceName;
    }

    string getIssueDate() const
    {
        return issueDate;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    string getSellerName() const
    {
        return sellerName;
    }

    unsigned int getSellerGstNo() const
    {
        return sellerGstNo;
    }

    string getBuyerName() const
    {
        return buyerName;
    }

    unsigned int getSumTotal() const
    {
        return sumTotal;
    }

    // Setters
    void setInvoiceId(int id)
    {
        invoiceId = id;
    }

    void setInvoiceName(const string &name)
    {
        invoiceName = name;
    }

    void setIssueDate(const string &date)
    {
        issueDate = date;
    }

    void setDueDate(const string &date)
    {
        dueDate = date;
    }

    void setSellerName(const string &name)
    {
        sellerName = name;
    }

    void setSellerGstNo(unsigned int gstNo)
    {
        sellerGstNo = gstNo;
    }

    void setBuyerName(const string &name)
    {
        buyerName = name;
    }

    void setSumTotal(unsigned int total)
    {
        sumTotal = total;
    }
     void printAttributes() const {
        Document::printAttributes();
        std::cout << "Invoice ID: " << invoiceId << std::endl;
        std::cout << "Invoice Name: " << invoiceName << std::endl;
        std::cout << "Issue Date: " << issueDate << std::endl;
        std::cout << "Due Date: " << dueDate << std::endl;
        std::cout << "Seller Name: " << sellerName << std::endl;
        std::cout << "Seller GST No: " << sellerGstNo << std::endl;
        std::cout << "Buyer Name: " << buyerName << std::endl;
        std::cout << "Sum Total: " << sumTotal << std::endl<<endl<<endl;
    }
    Document *clone() override
    {
        return new Invoice(*this);
    }
};

class Report : public Document
{
protected:
    unsigned int reportId;
    string title;
    string content;
    string conclusion;

public:
    Report(){};
    unsigned int getReportId() const
    {
        return reportId;
    }

    string getTitle() const
    {
        return title;
    }

    string getContent() const
    {
        return content;
    }

    string getConclusion() const
    {
        return conclusion;
    }

    // Setters
    void setReportId(unsigned int id)
    {
        reportId = id;
    }

    void setTitle(const string &t)
    {
        title = t;
    }

    void setContent(const string &c)
    {
        content = c;
    }

    void setConclusion(const string &conc)
    {
        conclusion = conc;
    }
      void printAttributes() const override {
        Document::printAttributes();
        std::cout << "Report ID: " << reportId << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Content: " << content << std::endl;
        std::cout << "Conclusion: " << conclusion << std::endl<<endl<<endl;
    }
    Document *clone() override
    {
        return new Report(*this);
    }
};


class DocumentFactory
{
protected:

public:
    static Document* createPrototype(string str, Document* toCloneObject)
    {

        if (str == "Invoice" || str == "INVOICE" || str == "invoice")
        {
            if(!toCloneObject) return new Invoice();
            return toCloneObject->clone();
        }
        if (str == "Report" || str == "REPORT" || str == "report")
        {
             if(!toCloneObject) return new Report();
            return toCloneObject->clone();
        }

        return nullptr;
    }
};

class Client
{
public:
    Client()
    {
        Invoice* newInvoice =(Invoice*) DocumentFactory::createPrototype("Invoice",nullptr);
        Report* newReport  = (Report*) DocumentFactory::createPrototype("report",nullptr);

        newInvoice->setDocumentId(01);
        newInvoice->setDocumentName("newInvoice");
        newInvoice->setIssueDate("12.08.2023");
        newInvoice->setDueDate("12.09.2023");
        newInvoice->setInvoiceId(01);
        newInvoice->setSellerGstNo(21025462);
        newInvoice->setSellerName("Raj_Soni");
        newInvoice->setBuyerName("Demo_Buyer");
        newInvoice->setInvoiceName("First_Invoice");
        newInvoice->setSumTotal(10000000);
        newInvoice->printAttributes();

        newReport->setDocumentName("new_report");
        newReport->setDocumentId(02);
        newReport->setReportId(01);
        newReport->setTitle("new_report");
        newReport->setContent("la la lala lala la la lala");
        newReport->setConclusion("om namah shivay");
        newReport->printAttributes();

        Invoice* cloneInvoice =(Invoice*) DocumentFactory::createPrototype("Invoice",newInvoice);
        Report* cloneReport = (Report*)DocumentFactory::createPrototype("Report",newReport);

        cloneInvoice->setDocumentId(03);
        cloneInvoice->setDocumentName("second_Invoice");
        cloneInvoice->setInvoiceId(02);
        cloneInvoice->setInvoiceName("first Clone Invoice");
        cloneInvoice->printAttributes();

        cloneReport->setReportId(02);
        cloneReport->setDocumentId(04);
        cloneReport->setDocumentName("second Report");
        cloneReport->setTitle("first_cloneReport");
        cloneReport->printAttributes();

    }
};


int main()
{
    Client C1;
    return 0;
}
