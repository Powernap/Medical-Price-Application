% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010

\title[Interactive Visual Analysis of Cohort Study Data]%
      {Interactive Visual Analysis of Cohort Study Data}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[Paul Klemm et al.]
       {Paul Klemm$^{1}$, Kai Lawonn$^{1}$, Sylvia Gla{\ss}er$^{1}$, Steffen Oeltze-Jafra$^{1}$, Katrin Hegenscheid$^{2}$, Henry V{\"o}lzke$^{2}$, Bernhard Preim$^{1}$
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$Otto-von-Guericke University Magdeburg, Germany\\
         $^2$Ernst-Moritz-Arndt University Greifswald, Germany
%        $^2$ Another Department to illustrate the use in papers from authors
%             with different affiliations
       }

% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{27}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page


%-------------------------------------------------------------------------
\begin{document}

\maketitle

\begin{abstract}
Epidemiological population studies impose information about a set of subjects (a cohort) to characterize disease-specific risk factors.
%%
Cohort studies comprise heterogenous variables (features) describing the medical condition as well as demographic and lifestyle factors.
%%
The data are analyzed using a priori defined hypotheses to find statistically significant correlations between features (associations).
%%
Modern cohort studies incorporate medical image data.
%%
The statistically driven epidemiological workflow only allows to determine associations between image-derived metrics, such as distances extracted from landmarks of the segmentation model.
\\\\
We propose methods for analyzing image- centric cohort study data with focus on assessing influences of organ shape.
%%
To account for epidemiological key requirements such as reproducibility and statistical resilience of results, the epidemiological workflow is analyzed and divided into different steps.
%%
Based on this analysis, an Interactive Visual Analysis (IVA) approach is proposed that enables epidemiologists to examine both image-based as well as non-image data, e.g., sociodemographic features and attributes derived from the image data.
%%
This approach enables hypotheses validation and generation by incorporating human pattern recognition as well as data mining methods.
%%
Using all reliable information from the image segmentation linked to non-image features aims to unveil associations by applying an iterative analysis approach.

\begin{classification} % according to http://www.acm.org/class/1998/
% ToDo: [high] Update Classification
\CCScat{Computer Graphics}{I.3.3}{Picture/Image Generation}{Line and curve generation}
\end{classification}

\end{abstract}
%-------------------------------------------------------------------------
\section{Introduction and Project Background}

Epidemiology characterizes the influence of causes to disease and health conditions of defined populations.
%%
Cohort studies are population-based studies involving usually large numbers of randomly selected individuals and comprising numerous attributes, ranging from self-reported interview data to results from various medical examinations, e.g., blood and urine samples (\emph{features}).
%%
Since recently, medical imaging has been used as an additional instrument to assess risk factors and potential prognostic information.
%%
The statistically driven epidemiological workflow only allows to determine \emph{associations} between image-derived metrics, such as distances extracted from landmarks of the segmentation model.
%%

This work is the result of a collaboration between epidemiologists of the Study of Health in Pomerania (SHIP) \cite{SHIP} and computer scientists of the University of Magdeburg under the umbrella of the DFG Project "Visual Analysis in Public Health".
%%
The focus lies on developing novel techniques for analyzing both image- and non-image data of cohort studies simultaneously.
%%
We took the following steps to achieve this goal.

\begin{itemize}
	\item Building a Interactive Visual Analysis (IVA) system based on the analysis of the epidemiological workflow to allow rapid hypothesis validation- and generation \cite{Klemm2014VIS}.
	%%
	\item Combine shape variability visualization techniques with information visualizations of non-image data \cite{Klemm2014VIS}.
	%%
	\item Provide similarity measures and visualizations that involve associations between features out of the focus of the epidemiologists to allow for hypothesis generation \cite{Klemm2014BVM}.
	%%
	\item Use data mining to derive shape-based groups of subjects using clustering techniques \cite{Klemm2013VMV}.
	%%
	\item Use classification methods to derive insight into specific disease risk factors \cite{Klemm2015IVAPP}.
\end{itemize}
%
The proposed methods are introduced as part of an Interactive Visual Analysis approach presented in the following section.
%
All publications use a lumbar spine data set from the Study of Health in Pomerania \cite{SHIP}.
%
It consists of 6.753 subjects from two cohorts with 77 parameter compiled by domain experts.
%
The image data was segmented using a tetrahedron-based finite element model \cite{Rak2013}.

\section{Epidemiological Workflow Analysis}

Epidemiological data is analyzed for statistical resilience of features associated with an epidemiological outcome of a disease.
%
For example, when clinical observations suggest a correlation between breast fat content and breast cancer in women, these two features are extracted from the data and correlated.
%
\emph{Confounders} are features, which bias an epidemiological outcome next to analyzed features.
%
Age for example strongly correlates with most types of cancer and therefore a result needs to be age-adjusted.

To meet requirements for reproducibility and comprehensibility it is essential to understand the epidemiological workflow.
%
Visual analysis of cohort study data aims to extend the standard epidemiological workflow for the following aspects:
\begin{itemize}
	\item Enable epidemiologists to examine both image-based as well as non-image data, e.g., sociodemographic features and attributes derived from the image data.
	\item Provide methods that assess local variations of shape of a anatomical structure under different medical related or lifestyle influences.
	\item Visual validation of presumptions and hypothesis about heterogenous features influencing various diseases using appropriate visualizations.
	\item Use of data mining tools such as clustering or the principal component analysis provides possibilities to group subjects regarding shape or other features.
\end{itemize}
%
To create methods suitable for application in the epidemiological context it is essential to understand how epidemiologists work.
%
This workflow is briefly described in the following section.
%
%-------------------------------------------------------------------------
\subsection{The classic Epidemiological Workflow} \label{sec:epiworkflow}
\begin{figure}[htb]
 \centering
 \includegraphics[width=3.0in]{figures/workflow_comparison}
 \caption{Interactive Visual Analysis (\emph{IVA}) tools complement parts of the epidemiological workflow instead of replacing them. The appropriate combination of statistical and interactive-driven analysis shows promising potential to unveil the information in the data. (a) shows the standard epidemiological workflow, (b) the \emph{IVA} supported one.}
  \label{fig:workflowcomparison}
\end{figure}
%
Figure~\ref{fig:workflowcomparison} (left) presents the epidemiological workflow following Thew and colleagues, which is described as follows \cite{Thew2009}:
%
\begin{enumerate}
	\item A hypothesis is derived from observations made by clinicians in their daily routine.
	%
	\item A set of features depicting conditions affected by the hypothesis is compiled accordingly.
	%
	\item Confounding features are identified and taken into account (for example using stratification). 
	%
	\item Statistical methods, such as regression analysis, assess the association of selected features with the investigated disease.
\end{enumerate}
%
Reproducibility of results is an epidemiological key requirement.
%
It is difficult to achieve, since many physicians are involved when thousands of test persons are examined and interviewed.
%
If the data acquisition process changes, an information bias is introduced to the data, hampering inference in and between acquisition cycles.
%

In longitudinal cohort studies, grouping subjects using epidemiological features is essential in order to allow per-group risk determination.
%
Grouping depends on the underlying hypothesis.
%
Age for example is divided into groups (e.g. in 20 year steps) when investigating its influence on a condition.
%
These groups strongly depend on the condition of interest and therefore there is no standard on how to categorize them.

To determine whether a subject is prone to be affected by a certain disease, \emph{relative risks} are expressed through the evaluation of p-values, which indicate statistical significance.
%
% Statistical correlations are prone to \emph{confounding}, meaning that the association of two features is influenced by a third feature, which needs to be isolated.
% %
% A famous example for a confounder is the association between shoe size and mortality, where it can be observed that people with larger shoe size have a smaller life expectation than people with small shoe size.
% %
% The shoe size is actually associated with gender, where women have smaller feet than men but also a longer life expectation.
%
%Statistics tools such as \texttt{SPSS}\footnote{Product of IBM; \url{http://ibm.com/software/analytics/spss/}} play a major role for analyzing epidemiological data.
%
Graphic data representation is largely used to present results rather than gaining insight.

\begin{figure*}[htb]
 \centering
 % \includegraphics[width=1\textwidth, resolution=300]{figures/visualization}
 \includegraphics[width=1\textwidth]{figures/visualization}
 \caption{(Left) Screenshot from the \emph{IVA} system, which is divided as follows: (a) The sidebar containing all features as well as the groups defined in the analysis process; (b) the canvas area where features can be added via drag and drop and the visualization can be chosen automatically according to the data type; (c) the interactive pivot table showing the exact numbers for each displayed feature combination.
 %%
 The data displayed is used to analyze the lumbar spine.
 %%
 Features can be added freely on the canvas via drag and drop.
 %%
 Dropping the \emph{age} parameter on the already plotted \emph{body size} container creates a mosaic plot combining both features (right) \cite{Klemm2014VIS}.
 }
 \label{fig:visualization}
\end{figure*}
\subsection{Epidemiological Data} \label{EpidemiologicalData}
Epidemiological data are highly heterogenous and incomplete.
%
Information about medical history and examinations, genetic conditions, geographical data, questionnaire results and image data yield a complex data space for each subject.
%
For ethical, legal or medical reasons some features cannot be gathered for each subject.
%
The most obvious example are women-specific questions about menstrual status or number of born children.
%
Follow-up examinations or questions about conditions like medications taken after a diagnosed disease also yield features only available for a small amount of subjects.
%

Indicators for medical conditions as well as questions about a subject's lifestyle are also often \emph{dichotomous}--they have two manifestations (\emph{Yes} or \emph{No}).
%
Dichotomous data can also be derived by aggregating features to yield only two manifestations (e.g. subjects younger or older than 50 years).
%
Medical examinations mostly comprise categorical (e.g. levels of back pain) and continuous values (e.g. age or body size).

% \paragraph{Image acquisition.} \label{ImageAcquisition} Imaging techniques involving ionizing radiation for the subject are not suitable for ethical reasons.
% %
% Therefore, MRI is the main method for collecting cohort study imaging data.
% %
% The image quality is a tradeoff between accuracy and affordability \cite{Preim2014}.
% %
% This often yields image resolutions inferior to those of clinical day-to-day practice, which makes their analysis more challenging.
% %
% The equipment used to gather medical image data is kept, if possible, on the initial software and hardware version during a longitudinal study to ensure comparability in and between acquisition cycles.
%-------------------------------------------------------------------------
\noindent \textbf{Image analysis.} \label{ImageAnalysis} Decisions have to be made on how image data are \emph{compared} and \emph{quantified}.
%
Segmentation masks representing the voxels of an anatomical structure would be ideal, since many different key figures, e.g., volume, largest diameter or aspect ratio, can be derived from them.
%
Since reliable and efficient segmentation techniques for these data are not available in general, epidemiologists are forced to measure the data by hand, which is a very tedious work with respect to the number of necessary landmarks and the number of subjects.
%
Information derived by landmarks, such as top and bottom point of a vertebra, are by far not as expressive and versatile as segmentation masks describing its whole shape.
%
They are also prone to a high inter-observer variability and are hard to reproduce.
%
This gains even more importance when analyzing multiple time steps.
%
Morphometric information from landmarks comprises thickness, diameter or length of a structure as well as grey value distribution in an area (used for determining the type of tissue) \cite{Preim2014}.

% \section{The Study of Health in Pomerania (SHIP)}
% After the pioneering Rotterdam study (started in 1990), several MR imaging study initiatives have evolved.
% %
% They slightly differ in clinical focus, acquired data and epidemiological research questions.
% %
% Starting in 1997 with a cohort consisting of 4,308 subjects, the \texttt{SHIP}, located in Northern Germany, aims to characterize health and disease in the widest range possible \cite{Volzke2011}.
% %
% Data is collected without focus on a group of diseases.
% %
% This allows the data set to be queried regarding many different diseases and conditions.
% %
% Subjects were examined in a 5-year time span, continuously adding new parameters including MRI scans in the last iteration \cite{Hegenscheid2009}.
% %
% The MRI protocol features a rich number of sequences.
% %
% A second cohort \texttt{SHIP-Trend} was established in 2008.
% %
% The protocols for examining the subjects between \texttt{SHIP} and \texttt{SHIP-Trend} remained the same, making them comparable.
% %
% The overall examination time for each person attending the study is two days.
%-------------------------------------------------------------------------

\section{Interactive Visual Analysis of Cohort Study Data}

The proposed \emph{IVA} workflow (Fig~\ref{fig:workflowcomparison} (right)) knows three major steps: Feature selection, visualization and brushing.
%
A hypothesis-driven analysis usually starts with the selection of features.
%
A feature selection from a shape-based clustering creates shape groups.
%
\emph{Hypothesis generation} with focus on image data starts with a shape-based clustering.
%
The feature is mapped using an automatically chosen visualization appropriate for its data type. %(described in detail in the following section).
%
The visualization techniques have to combine both image-and non-image data in order to set domain and range data in relation to each other.
%
In our system, the visualization can either be brushed or new features can be added to the analysis. 
%Subsequently the visualization can be either brushed or new features can be added to the analysis.
%
Brushing methods are subdivided using the previously described \emph{IVA} patterns.
%
Brushed regions are treated like features as they divide the subject space just like categorical features. %and lead therefore to a new feature selection.
%
Selecting features also triggers a \emph{multivariate analysis} using contingency values to highlight features associated with selected features.
%
%The starting point of \emph{IVA Loop} is determined whether the analysis is hypothesis-driven or exploratory.
%
%An analysis with the aim of hypothesis generation of image-based data starts with a clustering of the structure 
%
A sample workflow using interaction and visualization techniques can be seen in Figure~\ref{fig:visualization} \cite{Klemm2014VIS}.

\noindent \textbf{Visualization and Analysis of Organ Shape Variability}. 
\emph{Hypothesis generation} based on organ shape is triggered by suggesting interesting feature correlations.
%
This allows for assessment of shape groups, which can not be accomplished with standard epidemiological methods.
%
% The contributions are:
% \begin{itemize}
% 	\item generation of groups of individuals sharing a similar shape of the lumbar spine canal,
% 	\item visualization of these groups by means of representatives.
% %	\item 
% \end{itemize}
Clustering using Agglomerative Hierarchical Clustering is carried out to form groups that exhibit low intra-group and high inter-group shape variability \cite{Klemm2013VMV}. 
%
The clusters are visualized by means of representatives to reduce visual clutter and simplify a comparison between subgroups of the cohort.
%
Figure~\ref{fig:hypopthesisbased} shows a clustering results for subjects with lumbar back pain, which leads to interesting results regarding major shape classes as well as potentially pathological outliers \cite{Klemm2013VMV}.
\begin{figure}[htb]
 \centering
 %\includegraphics[width=1.5in]{figures/InteractionLoop}
 \includegraphics[width=3.0in]{figures/hypothesisbased}
 \caption{(a) Dichotomous questionnaire answer to ``\emph{Did you experience back pain in the past three months?}''.
 %
 Mean shapes between the groups show no difference.
 %
 (b) Shape-based clustering for all subjects who suffered from back pain yields 6 groups. 
 %
 Note that the difference in subject count is due to the missing shape information for some subjects.
 %
% The total count of subjects in (b) is smaller 
 }
 \label{fig:hypopthesisbased}
\end{figure}

%% ---------------------------------
\noindent \textbf{Interactive Visual Analysis of Lumbar Back Pain}. 
Decision trees are incorporated to assess the discriminative power of image parameters derived from the lumbar spine segmentation model presented in \cite{Klemm2013VMV} towards back pain related variables.
%%
A decision tree classifier was calculated for each non-image variable and assessed towards classification accuracy and number of decision rules.
%%
Low classification errors by trees with few decision rules are preferred.
%%
A interactive scatter plot represents each decision tree as data point using the accuracy number of rules, allowing for a fast overview visualization.
%
Decision trees for each data point can be examined in detail by interacting with the scatter plot.
%%
The work concludes that the given model precision is not enough to characterize back pain, but allows to classify other non-image variables, such as the subject age when he or she started smoking \cite{Klemm2015IVAPP}.
%% ---------------------------------

\noindent \textbf{Hypothesis-generation using Overview Visualizations}.
\begin{figure}[htb]
 \centering
 \includegraphics[width=3.0in]{figures/similarity_matrix}
 \caption{Contingency matrix of 129 variables (127 data set variables, 2 cluster results) showing 16,641 combinations based on \emph{Cram\'{e}r's V} contingency values.
 %
 Color brightness encodes association strength.
 %Mouse-over focuses a entry and highlights the feature names for better readability.
 Moving the mouse over an entry enlarges the variable names for better readability.
 % Potential Cut here
 %The enlarged excerpt shows associations for shape clusters of subjects with and without diagnosed spine attrition, which show associations between gender, weight, body height and smoking behavior.
 }
 \label{fig:contingencymatrix}
\end{figure}
Overview visualizations for non-image variables or image-derived variables can be provided using contingency values, such as \emph{Cram\'{e}r's V}.
%%
These values can be used to create a contingency matrix, which displays correlations between variables (Fig.~\ref{fig:contingencymatrix}).
%%
In a qualitative evaluation, epidemiologists used this visualizations to observe potential unexpected correlations, forming a new hypothesis, which serves as starting point for a new analysis \cite{Klemm2014VIS}.

%% ---------------------------------
%\noindent \textbf{Hypothesis-generation using Overview Visualizations}.
%
\section{Conclusion and Future Work}
We presented IVA tools for image and non-image centric cohort study data.
%%
The methods aim to complement weaknesses of the existing epidemiological workflow rather than replacing it.
%%
Overview visualizations of both image and non-image data allow for explorative analysis of cohort study data, which was not possible for our collaborators before.
%%
Using these techniques, new insights about possible risk factors and parameter associations could be derived.
%%

Future work in this field comprises methods for providing overview visualizations for multivariate correlations using regression models.
%%
As (semi-)automatic image segmentation algorithms become available to epidemiologists, new body structures can be included into the analysis system.
%%
This also requires the identification of structure specific measures, e.g. curvature for the spine canal or volume of the liver.
%%

Applying Visual Analysis methods into the epidemiological workflow is still very unfamiliar to domain experts.
%%
Methods need to meet the high quality standards of epidemiological research while trying to provide new insight into the data.
%%
Meeting both of these requirements is challenging.
%%
The complexity of the underlying data make cohort studies a promising field for developing new IVA methods.

\bibliographystyle{style/eg-alpha-doi}

\bibliography{bibliography}

%-------------------------------------------------------------------------
\newpage

\end{document}
