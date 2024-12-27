#' Example R object
#'
#' @description
#' R object wrapping an external pointer to a C++ class

Example <- R6::R6Class(
    classname = "Example",
    cloneable = FALSE,
    public = list(

        #' @field example_ptr External pointer to a C++ Example class
        example_ptr = NULL,

        #' @description
        #' Create a new Example object.
        #' @param vec_size Size of the C++ vector of `ObjectData` elements
        #' @return A new `Example` object.
        initialize = function(vec_size) {
            self$example_ptr <- create_example_class_cpp(vec_size)
        },

        #' @description
        #' Code to run when Example object is removed
        finalize = function() {
            print("Running the R object finalizer")
            delete_example_class_cpp(self$example_ptr)
        }
    )
)

#' Create an `Example` object
#'
#' @param vec_size Size of the C++ vector of `ObjectData` elements
#'
#' @return `Example` object
#' @export
createExample <- function(vec_size){
    return(invisible((
        Example$new(vec_size)
    )))
}
