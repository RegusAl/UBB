import numpy as np
from scipy.spatial.distance import cdist

class KMeans:
    def __init__(self, n_clusters, max_iter=500, k=0.0001):
        self.n_clusters = n_clusters
        self.max_iter = max_iter
        self.k = k

    def fit(self, X):
        # Randomly initialize the centroids
        initial_indices = np.random.permutation(X.shape[0])[:self.n_clusters]
        self.centroids = X[initial_indices]

        for _ in range(self.max_iter):
            # Assign clusters
            distances = cdist(X, self.centroids, 'euclidean')
            self.labels = np.argmin(distances, axis=1)
            
            # Compute new centroids
            new_centroids = np.array([X[self.labels == j].mean(axis=0) for j in range(self.n_clusters)])

            # Check for convergence
            if np.all(np.abs(new_centroids - self.centroids) <= self.k):
                break
            
            self.centroids = new_centroids
        
    def predict(self, X):
        distances = cdist(X, self.centroids, 'euclidean')
        return np.argmin(distances, axis=1)