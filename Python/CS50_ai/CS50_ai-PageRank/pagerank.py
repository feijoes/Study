
import os
import random
import re
import sys




DAMPING = 0.85
SAMPLES = 10000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    corpus = crawl(sys.argv[1])
    
    #ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    #print(f"PageRank Results from Sampling (n = {SAMPLES})")
    #for page in sorted(ranks):
    #    print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
#

def crawl(directory):
    
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """
    #making the probality
    probality = dict()
    for key in corpus.keys():
        probality[key] = 0
    
    for i in corpus:
        probality[i] += (1 - damping_factor) / len(corpus)

    for i in corpus[page]:
        probality[i] += damping_factor / len(corpus[page])
    
    return probality
    
     
        
        
    


def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    probality = dict()
    for key in corpus.keys():
        probality[key] = 0
    page = random.choice(list(corpus))    
    for _ in range(n):
        result = transition_model(corpus, page, damping_factor)
        page = random.choices(list(result.keys()),weights=list(result.values()),k=1)[0]
        for name in result:
            probality[name] += result[name]
    for i in probality:
        probality[i] = probality[i] / n
    
  
    return probality
        

    


def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    probality = dict()
    for key in corpus.keys():
        probality[key] = 1 / len(corpus)
    value = 0.001
    while True:
        # This process should repeat until no PageRank value changes by more than 0.001 between the current rank values and the new rank values 
        try:
            if abs(check[list(probality.keys())[-1]] - rank) < value:
                break
        except UnboundLocalError:
            pass
        for p in corpus:
            rank = (1-damping_factor) / len(corpus)
            for i in corpus:
                if p in corpus[i]:
                    rank +=  damping_factor*(probality[i] / len(corpus[i]))
                elif not corpus[i]:
                    rank += damping_factor*(probality[i] / len(corpus))
            check = probality.copy()    
            probality[p] = rank
    print(sum(probality.values()))
    return probality
if __name__ == "__main__":
    main()
