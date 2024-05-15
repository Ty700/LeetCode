# 1472. Design Browser History

# You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

# Implement the BrowserHistory class:

#     BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
#     void visit(string url) Visits url from the current page. It clears up all the forward history.
#     string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
#     string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

class Page(object):
    def __init__(self, page):
        self.page = page
        self.next = None
        self.prev = None
    
class BrowserHistory(object):

    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.top = Page(homepage)

    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        new_page = Page(url)
        new_page.prev = self.top
        self.top.next = new_page
        self.top = new_page

    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        i = 0
        while self.top.prev and i < steps:
            self.top = self.top.prev
            i += 1
        
        return self.top.page

    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        i = 0
        while self.top.next and i < steps:
            self.top = self.top.next
            i += 1
        return self.top.page

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
