\name{cec2005benchmark3}
\alias{cec2005benchmark3}
\title{Function Number 3}
\description{
Shifted Rotated High Conditioned Elliptic Function
\itemize{
  \item \eqn{x \in [-100,100]^D}
  \item Global optimum \eqn{F(x^*) = -450}
}
}
\usage{
cec2005benchmark3(x)
}
\arguments{
  \item{x}{Either a vector with 2, 10, 30 or 50 elements or a matrix with
  the same number of columns and one row for each vector to be evaluated}
}
\value{
A vector with the evaluation of the function for each row of \code{x}
}
\references{
P. N. Suganthan, N. Hansen, J. J. Liang, K. Deb, Y.-P. Chen, A. Auger,
S. Tiwari (2005). Problem Definitions and Evaluation Criteria for the
CEC 2005 Special Session on Real-Parameter Optimization, Technical
report, Nanyang Technological University, Singapore, May 2005,
\url{http://www.ntu.edu.sg/home/EPNSugan/index_files/CEC-05/CEC05.htm}.
}
\seealso{
\code{\link{cec2005benchmark}}
}
\examples{
cec2005benchmark3(runif(10, -100, 100))
}
